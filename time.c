/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*cut_time(char *str, int start, int end)
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	len = end - start;
	new = (char*)malloc(len + 1);
	while (start <= end)
	{
		new[i] = str[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

char			*get_time(char *dst, char *ori)
{
	int		i;
	char	*new;

	i = 0;
	ft_memset(dst, 0, 100);
	while (ori[i] != '\0')
	{
		if (ori[i] == '\n')
			break ;
		dst[i] = ori[i];
		i++;
	}
	new = cut_time(dst, 4, 15);
	return (new);
}
