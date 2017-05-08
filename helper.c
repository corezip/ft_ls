/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				else_helper(struct stat filestat, t_top *x, char *file)
{
	if (S_ISDIR(filestat.st_mode))
	{
		if (S_ISDIR(filestat.st_mode) && x->flag.rr == 0)
			dir_arg(x, file);
		else
			get_file2(file, x);
	}
	else
		ft_printf("%s\n", file);
}

/*
** GET_FILE_T
** ---------------------------------------------------------------------------
** Con esta funcion sabremos el camino que tomara el file que fue introducido
** por argumento.
*/

void				get_file_t(char *file, t_top *x)
{
	struct stat		filestat;

	if (stat(file, &filestat) < 0)
		perror("Error: ");
	if (S_ISDIR(filestat.st_mode))
	{
		x->type.flag = 1;
		x->type.j = -1;
		x->flag.rr = 1;
		x->flag.rec = 2;
		recurtion_mexa_t(file, x, -1);
	}
	else if (x->flag.l > 0)
		print_value_ls(file);
	else
		ft_printf("%s\n", file);
}

/*
** FT_SWAPCHAR
** ---------------------------------------------------------------------------
** Esta funcion hara un simple cambio de nombres en la matrix donde se
** almacenan los nombres de los archivos.
*/

void				ft_swapchar(char **a, char **b)
{
	char			*c;

	c = ft_strdup(*a);
	*a = ft_strdup(*b);
	*b = ft_strdup(c);
}

/*
** FT_MAKE_MATRIX
** ---------------------------------------------------------------------------
** Esta funcion hara una matriz para almacenar los nombres de los files del
** directorios en donde se esta trabajando.
*/

char				**ft_make_matrix(int size, t_top *x, char *path)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	int				i;
	char			**matrix;

	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	pdir = opendir(path);
	i = 0;
	while ((pdirent = readdir(pdir)) != NULL)
	{
		if (pdirent->d_name[0] == '.' && x->flag.a >= 1)
		{
			matrix[i] = ft_strdup(pdirent->d_name);
			i++;
		}
		else if (pdirent->d_name[0] != '.' && (x->flag.a == 0 ||
			x->flag.a >= 1))
		{
			matrix[i] = ft_strdup(pdirent->d_name);
			i++;
		}
	}
	matrix[i] = NULL;
	closedir(pdir);
	return (matrix);
}

/*
** FT_LENDIR
** ---------------------------------------------------------------------------
** Con esta funcion obtendremos el numero de archivos que tiene el directorio
** donde estamos trabajando.
*/

int					ft_lendir(t_top *x, char *path)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	int				i;

	pdir = opendir(path);
	i = 0;
	while ((pdirent = readdir(pdir)) != NULL)
	{
		if (pdirent->d_name[0] == '.' && x->flag.a >= 1)
			i++;
		else if (pdirent->d_name[0] != '.' && (x->flag.a == 0 ||
			x->flag.a >= 1))
			i++;
	}
	closedir(pdir);
	return (i);
}
