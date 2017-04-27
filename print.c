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

void				print_blocks_size(t_top *x, char* path)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	int				i;
	struct stat		buff;

	pdir = opendir(path);
	i = 0;
	while ((pdirent = readdir(pdir)) != NULL)
	{
		
		stat(pdirent->d_name, &buff);
		// ft_printf(">>>%d<<<%d>>>%s\n", i, x->type.size, pdirent->d_name);
		if (pdirent->d_name[0] != '.' && (x->flag.a == 0 || x->flag.a == 1))
		{			x->type.size += buff.st_blocks;
			i++;
		}
		else if(pdirent->d_name[0] == '.' && x->flag.a >= 1)
		{
			x->type.size += buff.st_blocks;
			i++;
		}
	}
	ft_printf("Total: %d\n", x->type.size);
	closedir(pdir);
}

int		print_value_recu(char *file, char* path)
{
	char date[40];
	struct stat fileStat;
	struct passwd *pw;
	struct group  *gr;
	char *tmp;

	path = ft_strjoin(path, "/");
	tmp = ft_strjoin(path, file);
	lstat(tmp, &fileStat);
	pw = getpwuid(fileStat.st_uid);
	gr = getgrgid(fileStat.st_gid);
	ft_printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	ft_printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf("  %d %s  %s %7d ", fileStat.st_nlink, pw->pw_name,
		gr->gr_name, fileStat.st_size);
	ft_printf("%s %s\n", ft_strsub(ctime(&fileStat.st_ctime), 4, 12), file);
	return (fileStat.st_blocks);
}

int		print_value_ls(char *file, char* path)
{
	char date[36];
	struct stat fileStat;
	struct passwd *pw;
	struct group  *gr;

	if (lstat(file, &fileStat) < 0)
		return 1;
	pw = getpwuid(fileStat.st_uid);
	gr = getgrgid(fileStat.st_gid);
	ft_printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	ft_printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf("  %d %s  %s %7d ", fileStat.st_nlink, pw->pw_name,
		gr->gr_name, fileStat.st_size);
	ft_printf("%s %s\n", ft_strsub(ctime(&fileStat.st_ctime), 4, 12), file);
	return (fileStat.st_blocks);
}

void			print_basic(t_top *x, char *path)
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
			ft_printf("%s\n", matrix[x->type.j]);
}
