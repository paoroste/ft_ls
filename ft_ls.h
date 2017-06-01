/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:38:50 by paoroste          #+#    #+#             */
/*   Updated: 2017/06/01 18:59:57 by paoroste         ###   ########.fr       */
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

typedef struct	s_opt
{
	int		a;
	int		l;
	int		up_r;
	int		r;
	int		t;
}				t_opt;

typedef struct	s_elem
{

	char			*name;
	char			*path;
	uid_t			uid;
	gid_t			gid;
	mode_t			mode;
	dev_t			rdev;
	time_t			date;
	off_t			size;
	quad_t			blocks;
	nlink_t			nlink;
	struct s_elem	*next;

}				t_elem;

int				one_of(char c, char *str);
void			error_arg(char arg);
void			error(char *str, char *error, int nb);
void			core(t_opt arg, t_list *path, int reps);
void			get_info(t_elem **files, char *name, char *path, t_opt arg);

#endif
