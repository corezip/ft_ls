/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			**nombres(char **nombre, char *variable, int x)
{
	int		i;

	i = 0;
	while (variable[i])
		i++;
	nombre[x] = (char*)malloc(i + 1);
	i = -1;
	while (variable[++i])
		nombre[x][i] = variable[i];
	nombre[x][i] = '\0';
	return (nombre);
}

/************************************************/

void			recurtion_mexa(char *path, t_top *x, int i)
{
	struct stat	fileStat;
	char		**matrix;
	char		*tmp;

	if (x->flag.l >= 1)
	{
		x->type.i = ft_lendir(x, path);
		matrix = ft_make_matrix(x->type.i, x, path);
		print_value_ls(matrix, path);
		while (matrix[i] != NULL)
		{
			
			tmp = ft_strjoin(path, "/");
			tmp = ft_strjoin(tmp, matrix[i]);
			
			lstat(tmp, &fileStat);
			if(S_ISDIR(fileStat.st_mode))
			{
				matrix[i] = ft_strdup(tmp);
				ft_printf("\n\n\n\n%s", matrix[i]);
				ft_printf("\n");
				recurtion_mexa(matrix[i], x, 0);
			}
			i++;
		}
	}
	else
	{
		x->type.i = ft_lendir(x, path);
		matrix = ft_make_matrix(x->type.i, x, path);
		comp_matrix_r(x, matrix);
		while (matrix[i] != NULL)
		{
			
			tmp = ft_strjoin(path, "/");
			tmp = ft_strjoin(tmp, matrix[i]);
			
			lstat(tmp, &fileStat);
			if(S_ISDIR(fileStat.st_mode))
			{
				matrix[i] = ft_strdup(tmp);
				ft_printf("\n\n\n\n%s", matrix[i]);
				ft_printf("\n");
				recurtion_mexa(matrix[i], x, 0);
			}
			i++;
		}
	}
}

/*****************************************************/

void			comp_matrix(t_top *x, char **matrix, char* path)
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
		print_value_ls(matrix[x->type.j], path);
}

void			comp_matrix_r(t_top *x, char **matrix)
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


int				main(int argc, char *argv[])
{
	t_top	*x;

	x =(t_top*)malloc(sizeof(t_top));
	if (argc >= 1)
	{
		if (argc == 1)
			print_basic(x);
		else if (argc >= 2)
		{
			start_flag(argv, x);
			if (flag_on(x))
				print_l(x);
			else
				ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls \
					[-Ralrt] [file ...]\n", argv[1][1]);
		}
	}
	return (0);
}
