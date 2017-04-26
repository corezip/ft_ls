/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		recursion_comp_rev(t_top *x, char **matrix)
{
	while (x->type.flag != 0)
	{
		x->type.flag = 0;
		while(matrix[x->type.j] != NULL)
		{
			if (matrix[x->type.j + 1] && ft_strcmp(matrix[x->type.j],
				matrix[x->type.j + 1]) < 0)
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

void comp_rev(t_top *x, char **matrix, char *path)
{
	while (x->type.flag != 0)
	{
		x->type.flag = 0;
		while(matrix[x->type.j] != NULL)
		{
			if (matrix[x->type.j + 1] && ft_strcmp(matrix[x->type.j],
				matrix[x->type.j + 1]) < 0)
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
	{
		if (x->flag.rr >= 1)
			print_value_recu(matrix[x->type.j], path);
		else
			print_value_ls(matrix[x->type.j], path);
	}
}

void comp_normal(t_top *x, char **matrix, char *path)
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
	{
		if (x->flag.rr >= 1)
			print_value_recu(matrix[x->type.j], path);
		else
			print_value_ls(matrix[x->type.j], path);
	}
}
