/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:38:50 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/04 14:17:03 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <uuid/uuid.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "./libft/srcs/libft.h"

typedef struct		s_opt
{
	int				up_r;
	int				a;
	int				l;
	int				r;
	int				t;
	int				prpath;
	int				zero;
	long long		blocks;
	char			*cblocks;
	char			*path;
	int				aff;
	int				c;
	int				s;
}					t_opt;

typedef struct		s_file
{
	char			*d_name;
}					t_file;

typedef struct		s_elem
{
	char			*path;
	char			*d_name;
	char			*rights;
	char			*size;
	char			*nlink;
	char			*link;
	char			*date;
	char			*gr_name;
	char			*usr_name;
	int				i;
	struct s_file	*file;
	struct stat		fstat;
	struct s_elem	*next;
	struct passwd	*usr;
	struct group	*group;
	struct s_elem	*prev;
}					t_elem;

void				error_unknow(int ac, char **av, t_opt arg, int a);
void				not_dir(int ac, char **av, t_opt arg, int a);
char				**arg_ascii(int ac, char **av, t_opt arg, int a);
int					check_uni(char *str);
int					check_date(time_t now, time_t mtime);
void				up_r(t_elem *list, t_opt arg);
int					check_nl(int nl, int nl2, char c);
int					check_min(dev_t result);
int					check_maj(dev_t result);
int					check(int size);
int					check_ma(t_elem *list);
int					more_check(t_elem *tmp, int size);
char				*more_rights(t_elem *list, char *str);
void				error_arg(char arg);
void				erase(t_elem *list);
int					error(char *str, char *error, t_opt arg);
t_elem				*get_info(t_elem *list, struct dirent *fichier,
		char *path, t_opt arg);
t_elem				*ft_ls_sort(t_elem *list, t_opt arg);
t_opt				get_more_info(t_elem *tmp, t_elem *list, t_opt arg);
void				get_time_mm(t_elem *list, t_opt arg, int size, int nlink);
char				*itoa_long(long long nb);
void				put_time(t_elem *list);
void				ft_ls(t_elem *list, t_opt arg, int i);
int					core(char *path, t_opt arg);

#endif
