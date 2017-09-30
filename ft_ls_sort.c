/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:57:30 by paoroste          #+#    #+#             */
/*   Updated: 2017/09/27 18:27:42 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_swap(t_elem *list, t_elem *tmp)
{
	struct file		*tmp_file;
	struct stat		tmp_fstat;
	char			*str;
	char			*tmp_link;

	str = list->path;
	tmp_link = list->link;
	tmp_file = list->file;
	tmp_fstat = list->fstat;
	list->link = tmp->link;
	list->fstat = tmp->fstat;
	list->file = tmp->file;
	list->path = tmp->path;
	tmp->link = tmp_link;
	tmp->file = tmp_file;
	tmp->fstat = tmp_fstat;
	tmp->path = str;
}

t_elem			*sort_t(t_elem *list)
{
	t_elem		*tmp;
	t_elem		*tmp1;

	tmp = list;
	tmp1 = list;
	while (tmp1)
	{
		while (tmp)
		{
			if ((tmp1->fstat.st_mtime - tmp->fstat.st_mtime) < 0)
				ls_swap(tmp1, tmp);
			tmp = tmp->next;
		}
		tmp1 = tmp1->next;
		tmp = tmp1;
	}
	return (list);
}

t_elem		*ft_ls_sort(t_elem *list, t_opt arg)
{
	if (arg.t == 1)
		return (sort_t(list));
	t_elem		*tmp;
	t_elem		*tmp1;

	tmp = list;
	tmp1 = list;
	while (tmp1)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp1->file->d_name, tmp->file->d_name) > 0)
				ls_swap(tmp1, tmp);
			tmp = tmp->next;
		}
		tmp1 = tmp1->next;
		tmp = tmp1;
	}
	return (list);
}
