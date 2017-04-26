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

int			flag_on(t_top *x)
{
	if (x->flag.l > 0)
		return (1);
	else if (x->flag.rr > 0)
		return (1);
	else if (x->flag.a > 0)
		return (1);
	else if (x->flag.r > 0)
		return (1);
	else if (x->flag.t > 0)
		return (1);
	return (0);
}

// void		get_file(char **argv, t_top *x, int argc)
// {
// 	char **files;
// 	int i;

// 	i = 0;
// 	files = (char**)malloc(sizeof(char*) * argc);
// 	while (argv[i])
// 	{
// 		files[i] = 
// 	}
// }

void		start_flag(char **argv, t_top *x, int argc)
{
	int i;
	int j;

	i = 1;
	j = 1;
	if (argv[i][0] == '-')
	{
		while (argv[i])
		{
			while (argv[i][j])
			{
				x->flag.l += (argv[i][j] == 'l') ? 1 : 0;
				x->flag.rr += (argv[i][j] == 'R') ? 1 : 0;
				x->flag.a += (argv[i][j] == 'a') ? 1 : 0;
				x->flag.r += (argv[i][j] == 'r') ? 1 : 0;
				x->flag.t += (argv[i][j] == 't') ? 1 : 0;
				j++;
			}
			i++;
			j = 1;
		}
	}
	// else
	// 	get_file(argv, x, argc);
}
