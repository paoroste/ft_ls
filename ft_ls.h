/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:38:50 by paoroste          #+#    #+#             */
/*   Updated: 2017/07/05 20:19:32 by paoroste         ###   ########.fr       */
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

void			error_arg(char arg);
int				error(char *str, char *error, t_opt arg);
t_elem			*get_info(t_elem *list, struct dirent *file, char *path, t_opt arg);
t_elem			*ft_ls_sort(t_elem *list, t_opt arg);
void			ft_ls(t_elem *list, t_opt arg, int i);

#endif
