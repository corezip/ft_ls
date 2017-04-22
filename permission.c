/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	second_step_con_3(t_top *x)
{
	if (x->type.nums[x->type.i] == '4')
	{
		x->type.perm[x->type.j++] = 'r';
		x->type.perm[x->type.j++] = '-';
		x->type.perm[x->type.j++] = '-';
	}
	else if (x->type.nums[x->type.i] == '5')
	{
		x->type.perm[x->type.j++] = 'r';
		x->type.perm[x->type.j++] = '-';
		x->type.perm[x->type.j++] = 'x';
	}
	else if (x->type.nums[x->type.i] == '6')
	{
		x->type.perm[x->type.j++] = 'r';
		x->type.perm[x->type.j++] = 'w';
		x->type.perm[x->type.j++] = '-';
	}
	else if (x->type.nums[x->type.i] == '7')
	{
		x->type.perm[x->type.j++] = 'r';
		x->type.perm[x->type.j++] = 'w';
		x->type.perm[x->type.j++] = 'x';
	}
}

void	second_step_con_2(t_top *x)
{
	if (x->type.nums[x->type.i] == '0')
	{
		x->type.perm[x->type.j++] = '-';
		x->type.perm[x->type.j++] = '-';
		x->type.perm[x->type.j++] = '-';
	}
	else if (x->type.nums[x->type.i] == '1')
	{
		x->type.perm[x->type.j++] = '-';
		x->type.perm[x->type.j++] = '-';
		x->type.perm[x->type.j++] = 'x';
	}
	else if (x->type.nums[x->type.i] == '2')
	{
		x->type.perm[x->type.j++] = '-';
		x->type.perm[x->type.j++] = 'w';
		x->type.perm[x->type.j++] = '-';
	}
	else if (x->type.nums[x->type.i] == '3')
	{
		x->type.perm[x->type.j++] = '-';
		x->type.perm[x->type.j++] = 'w';
		x->type.perm[x->type.j++] = 'x';
	}
	second_step_con_3(x);
}

char	*second_step_con(t_top *x)
{
	x->type.j = 1;
	x->type.i = 3;
	if (x->type.perm[0] == 'd' || x->type.perm[0] == 'l')
		x->type.i = 2;
	while (x->type.nums[x->type.i])
	{
		second_step_con_2(x);
		x->type.i++;
	}
	x->type.nums[10] = '\0';
	return (x->type.perm);
}

char	*type_converter(t_top *x)
{
	x->type.nums = ft_l_itoa_base(x->type.num, 8);
	if (x->type.nums[0] == '1' && x->type.nums[1] == '0'
		&& x->type.nums[2] == '0')
		x->type.perm[0] = '-';
	else if (x->type.nums[0] == '2' && x->type.nums[1] == '0')
		x->type.perm[0] = 'l';
	else if (x->type.nums[0] == '4' && x->type.nums[1] == '0')
		x->type.perm[0] = 'd';
	second_step_con(x);
	return (x->type.perm);
}
