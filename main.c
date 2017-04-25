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

void			ls_menu(t_top *x)
{
	char **matrix;

	x->type.size = 0;
	x->type.flag = 1;
	x->type.j = 0;
	if (x->flag.rr >= 1)
	{
		recurtion_mexa(".", x, 0);
		return ;
	}
	print_blocks_size(x, ".");
	x->type.i = ft_lendir(x, ".");
	matrix = ft_make_matrix(x->type.i, x, ".");
	comp_matrix(x, matrix, ".");
	while(matrix[++x->type.j] != NULL)
		print_value_ls(matrix[x->type.j], ".");
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
				ls_menu(x);
			else
				ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls \
					[-Ralrt] [file ...]\n", argv[1][1]);
		}
	}
	return (0);
}
