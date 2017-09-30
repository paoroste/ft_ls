/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:18:47 by paoroste          #+#    #+#             */
/*   Updated: 2017/09/25 19:07:18 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem		*info_src(t_elem *link)
{
	link = (t_elem*)malloc(sizeof(t_elem));
	link->i = 93;
	link->path = NULL;
	link->rights = NULL;
	link->size = NULL;
	link->nlink = NULL;
	link->link = NULL;
	link->date = NULL;
	link->file = NULL;
	link->usr = NULL;
	link->group = NULL;
	link->gr_name = NULL;
	link->usr_name = NULL;
	return (link);
}

t_elem		*do_prev(t_elem *list, t_elem *tmp)
{
	t_elem	*elem;

	elem = list;
	while(elem->next != tmp)
		elem = elem->next;
	return (elem);
}

int			is_link(t_elem *tmp)
{
	char	buf[256];
	int		ret;

	if ((ret = readlink(tmp->path, buf, 256)) != -1)
	{
		buf[ret] = '\0';
		tmp->link = ft_strdup(buf);
		return (1);
	}
	else
		tmp->link = NULL;
	return (0);
}

t_elem		*get_data(t_elem *elem, struct dirent *fichier, char *path, t_opt arg)
{
	elem->next = NULL;
	elem->file = (file*)malloc(sizeof(file));
	elem->file->d_name = ft_strdup(fichier->d_name);
	elem->path = ft_freejoin(path, elem->file->d_name, 0);
	if ((stat(elem->path, &elem->fstat)) == -1)
		elem->i = error("ft_ls: ", elem->file->d_name, arg);
	if (is_link(elem))
		if ((lstat(elem->path, &elem->fstat)) == -1)
			elem->i = error("ft_ls: ", elem->file->d_name, arg);
	return (elem);
}

t_elem		*get_info(t_elem *list, struct dirent *fichier, char *path, t_opt arg)
{
	t_elem		*tmp;

	tmp = list;
	if (list == NULL)
	{
		list = info_src(list);
		list = get_data(list, fichier, path, arg);
		list->prev = NULL;
		return (list);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = info_src(tmp);
	tmp = tmp->next;
	tmp = get_data(tmp, fichier, path, arg);
	tmp->prev = do_prev(list, tmp);
	return (list);
}
