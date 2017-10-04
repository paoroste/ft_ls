/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:58:36 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/03 13:42:52 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_nl(int nl, int nl2, char c)
{
	if (nl < nl2 && c == '.')
		return (nl2);
	else
		return (nl);
}

int			check_uni(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 127 || str[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

void		free_all(t_elem *link)
{
	if (link->path)
		free(link->path);
	if (link->rights)
		free(link->rights);
	if (link->size)
		free(link->size);
	if (link->nlink)
		free(link->nlink);
	if (link->link)
		free(link->link);
	if (link->date)
		free(link->date);
	if (link->file->d_name)
		free(link->file->d_name);
	if (link->file)
		free(link->file);
	if (link->gr_name)
		free(link->gr_name);
	if (link->usr_name)
		free(link->usr_name);
}

void		nul(t_elem *link)
{
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
}

void		erase(t_elem *list)
{
	while (list)
	{
		free_all(list);
		nul(list);
		if (list->next == NULL)
		{
			free(list);
			list = NULL;
		}
		else
			list = list->next;
		if (list)
		{
			free(list->prev);
			list->prev = NULL;
		}
	}
}
