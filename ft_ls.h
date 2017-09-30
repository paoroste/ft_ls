/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:38:50 by paoroste          #+#    #+#             */
/*   Updated: 2017/09/30 20:10:34 by paoroste         ###   ########.fr       */
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
	char			*err_name;
}					t_opt;

typedef struct		file
{
	char			*d_name;
}					file;

typedef struct		t_elem
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
	struct file		*file;
	struct stat		fstat;
	struct t_elem	*next;
	struct passwd	*usr;
	struct group	*group;
	struct t_elem	*prev;
}					t_elem;

int				check_nl(int nl, int nl2, char c);
t_opt			check_blocks(t_opt arg, long long blocks, char c);
int				check_min(dev_t result);
int				check_maj(dev_t result);
int				check(int size);
int				check_ma(t_elem *list);
int				more_check(t_elem *tmp, int size);
char			*more_rights(t_elem *list, char *str);
void			error_arg(char arg);
void			erase(t_elem *list);
int				error(char *str, char *error, t_opt arg);
t_elem			*get_info(t_elem *list, struct dirent *file, char *path, t_opt arg);
t_elem			*ft_ls_sort(t_elem *list, t_opt arg);
t_opt			get_more_info(t_elem *list, t_opt arg);
void			get_time_mm(t_elem *list, t_opt arg, int size, int nlink);
char			*itoa_long(long long nb);
void			put_time(t_elem *list);
void			ft_ls(t_elem *list, t_opt arg, int i);

#endif
