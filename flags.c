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

void		get_file2(char *file, t_top *x)
{
	struct stat fileStat;

	if (stat(file, &fileStat) < 0)
		perror("Error: ");
	if (S_ISDIR(fileStat.st_mode))
		{
			x->flag.rr = 1;
			recurtion_mexa(file, x, 0);
		}
		else
			print_value_ls(file, file);
}

void		get_file(char *file, t_top *x)
{
	struct stat fileStat;

	if (stat(file, &fileStat) < 0)
		perror("Error: ");
	x->flag.file = 1;
	if (x->flag.l >= 1)
	{
		print_blocks_size(x, file);
		get_file2(file, x);
	}
	else
	{
		if (S_ISDIR(fileStat.st_mode))
		{
			x->flag.rr = 1;
			recurtion_mexa(file, x, 0);
		}
		else
			ft_printf("%s\n", file);
	}
}

void		start_flag(char **argv, t_top *x)
{
	int i;
	int j;

	i = 1;
	j = 0;
	{
		while (argv[i])
		{
			if (argv[i][0] == '-')
			{
				while (argv[i][++j])
				{
					x->flag.l += (argv[i][j] == 'l') ? 1 : 0;
					x->flag.rr += (argv[i][j] == 'R') ? 1 : 0;
					x->flag.a += (argv[i][j] == 'a') ? 1 : 0;
					x->flag.r += (argv[i][j] == 'r') ? 1 : 0;
					x->flag.t += (argv[i][j] == 't') ? 1 : 0;
				}
			}
			else
				get_file(argv[i], x);
			j = 1;
			i++;
		}
	}
}
