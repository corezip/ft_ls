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

void			print_r(t_top *x, char *path)
{
	char		**matrix;

	x->type.flag = 1;
	x->type.j = 0;
	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
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

void			ls_menu(t_top *x, char *path)
{
	char		**matrix;

	x->type.size = 0;
	x->type.flag = 1;
	x->type.j = 0;
	if (x->flag.rr >= 1)
	{
		recurtion_mexa(path, x, 0);
		return ;
	}
	if (x->flag.a >= 1 && x->flag.l <= 0)
	{
		print_basic(x, path);
		return ;
	}
	if (x->flag.r >= 1 && x->flag.l <= 0)
	{
		print_r(x, path);
		return ;
	}
	print_blocks_size(x, path);
	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
	comp_matrix(x, matrix, path);
}

int				main(int argc, char *argv[])
{
	t_top		*x;
	
	x = (t_top*)malloc(sizeof(t_top));
	if (argc >= 1)
	{
		if (argc == 1)
			print_basic(x, ".");
		else if (argc >= 2)
		{
			start_flag(argv, x);
			if (flag_on(x) && x->flag.file <= 0)
				ls_menu(x, ".");
			else if (x->flag.file == 0)
				ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls" 
					" [-Ralrt] [file ...]\n", argv[1][1]);
		}
	}
	return (0);
}
