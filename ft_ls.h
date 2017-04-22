/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "./libft/libft.h"

/*
**************************************************************************
** *nums ---> contiene el valor convertido de los permisos ej. drwxr-xr-x.
** i y j ---> son simples contadores para los whiles o char*.
** size ---> es el tamaño en bytes de los archivos.
** flag --> ??????
** mtime ---> Es la variable donde vamos a recibir el tiempo.
** new_time ---> Es la variable del tiempo ya recortado listo para imprimir.
** perm ---> es la variable para poder hacer la conversion de los permisos.
**************************************************************************
*/

typedef	struct			s_perm
{
	int					i;
	int					j;
	int					size;
	int					num;
	int					flag;
	char				mtime[100];
	char				*nums;
	char				type[4];
	char				perm[10];
	char				*new_time;
}						t_perm;

/*
**************************************************************************
** Las flags sirven para saber si recibo "-".
**************************************************************************
*/

typedef	struct			s_flag
{
	int					l;
	int					rr;
	int					a;
	int					r;
	int					t;
}						t_flag;

/*
**************************************************************************
** Estructura general.
**************************************************************************
*/

typedef	struct			s_top
{
	t_perm				type;
	t_flag				flag;
}						t_top;

void					print_basic(t_top *x);
void					print_l(t_top *x);
char					*get_time(char *dst, char *ori);
char					*cut_time(char *str, int start, int end);
char					*type_converter(t_top *x);
char					*second_step_con(t_top *x);
void					second_step_con_2(t_top *x);
void					second_step_con_3(t_top *x);
int						find_newline(char *str);
void					start_flag(char **argv, t_top *x);
int						flag_on(t_top *x);
void					ft_swapchar(char **a, char **b);
void					ft_print_matrix(char **matrix);
char					**ft_make_matrix(int size, t_top *x, char* path);
int						ft_lendir(t_top *x, char *path);
int						print_value_ls(char *file, char *path);
void					print_blocks_size(t_top *x, char* path);
void					comp_matrix(t_top *x, char **matrix, char* path);
/*
*/
int						ft_lendir_r(t_top *x, char *path);
char					**ft_make_matrix_r(int size, t_top *x, char *path);
void					recurtion_mexa(char *path, t_top *x, int i);
void					comp_matrix_r(t_top *x, char **matrix);
void					especial_comp_matrix(t_top *x, char **matrix, char* path);
void					print_especial(char* path, char** matrix, int i);

#endif
