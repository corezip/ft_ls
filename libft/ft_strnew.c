/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:40:16 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/11 15:40:17 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void *x;

	x = malloc(size + 1);
	if (!x)
		return (NULL);
	ft_memset(x, 0, size + 1);
	((char *)x)[size + 1] = '\0';
	return ((void *)x);
}