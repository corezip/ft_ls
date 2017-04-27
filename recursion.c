/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			comp_matrix_r(t_top *x, char **matrix)
{
	if (x->flag.r >= 1)
		recursion_comp_rev(x, matrix);
	else
	{
		while (x->type.flag != 0)
		{
			x->type.flag = 0;
			while(matrix[x->type.j] != NULL)
			{
				if (matrix[x->type.j + 1] && ft_strcmp(matrix[x->type.j],
					matrix[x->type.j + 1]) > 0)
				{
					ft_swapchar(&matrix[x->type.j], &matrix[x->type.j + 1]);
					x->type.flag++;
				}
				x->type.j++;
			}
			x->type.j = 0;
		}
		x->type.j = -1;
		while(matrix[++x->type.j] != NULL)
			ft_printf("%s\n", matrix[x->type.j]);
	}
}

void			comp_matrix(t_top *x, char **matrix, char *path)
{
	x->type.flag = 1;
	x->type.j = 0;
	if (x->flag.r >= 1)
		comp_rev(x, matrix, path);
	else
		comp_normal(x, matrix, path);
}

void			recurtion_mexa(char *path, t_top *x, int i)
{
	struct stat	fileStat;
	char		**matrix;
	char		*tmp;

	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
	if (x->flag.l >= 1 || x->flag.file >= 1)
		comp_matrix(x, matrix, path);
	else
		comp_matrix_r(x, matrix);
	while (matrix[i] != NULL)
	{
		tmp = ft_strjoin(path, "/");
		tmp = ft_strjoin(tmp, matrix[i]);
		lstat(tmp, &fileStat);
		if(((S_ISDIR(fileStat.st_mode) && ft_strcmp(matrix[i], "."))) &&
			((S_ISDIR(fileStat.st_mode) && ft_strcmp(matrix[i], ".."))))
		{
				matrix[i] = ft_strdup(tmp);
				ft_printf("\n%s\n", matrix[i]);
				recurtion_mexa(matrix[i], x, 0);
		}
		i++;
	}
}
