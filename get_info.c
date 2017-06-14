/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:18:47 by paoroste          #+#    #+#             */
/*   Updated: 2017/06/14 15:51:10 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem		*info_src(char *name, char *path, t_opt arg)
{
	t_elem			*src;
	struct stat 	fstat;

	src = malloc(sizeof(src));
	src->name = ft_strdup(name);
	src->path = ft_strjoin(path, name);
	if (lstat(src->name, &fstat) == -1)
	{
		error("ft_ls: ", src->name, 1);
		return (NULL);
	}
	src->date = fstat.st_mtime;
	src->uid = fstat.st_uid;
	src->gid = fstat.st_gid;
	src->rdev = fstat.st_rdev;
	src->size = fstat.st_size;
	src->blocks = fstat.st_blocks;
	src->nlink = fstat.st_nlink;
	src->mode = fstat.st_mode;
	src->next = NULL;
	return (src);
}

int		get_info2(t_elem **files, struct dirent *file, char *path, t_opt arg)
{
	t_elem		*list;

	list = *files;
	if (!list)
		return (0);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = info_src(file->d_name, path, arg);
	}
	else
		*files = info_src(file->d_name, path, arg);
	return (1);
}

void		get_info(t_elem **files, char *name, char *path, t_opt arg)
{
	t_elem		*list;

	list = *files;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = info_src(name, path, arg);
	}
	else
		*files = info_src(name, path, arg);
}
