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

char				**ft_catching_time(int size, t_top *x, char **files, char *path)
{
	struct stat		filestat;
	int				i;
	char			**matrix;
	char			*tmp;
	char			*tmp2;
	char			*tmp3;

	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (files[i] != NULL)
	{
		if (ft_strcmp(path, ".") == 0)
		{
			tmp2 = ft_strjoin("./", files[i]);
			tmp = ft_strjoin(tmp2, "/");
			tmp3 = ft_strdup(tmp);
		}
		else
		{
			tmp = ft_strjoin(path, "/");
			tmp3 = ft_strjoin(tmp, files[i]);
		}
		lstat(tmp3, &filestat);
		matrix[i] = ft_strdup(ft_itoa(filestat.st_ctime));
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
} 
