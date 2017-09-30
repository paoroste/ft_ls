/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:44:31 by paoroste          #+#    #+#             */
/*   Updated: 2017/09/28 19:09:48 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_easy(t_elem *list, t_opt arg)
{
	if(list->i == 0)
		return (0);
	if (arg.a == 0 && list->file->d_name[0] == '.')
		return (0);
	ft_print("%s\n", list->file->d_name);
	return (0);
}

int			print_l(t_elem *list, t_opt arg, int i)
{
	if (list->i == 0)
		return (0);
	if (arg.a == 0 && list->file->d_name[0] == '.')
		return (0);
	if (list->link == NULL)
	{
		if (i == 0)
			printf("total %s\n", arg.cblocks);
		printf("%s %s %s  %s  %s %s %s\n", list->rights, list->nlink,
				list->usr_name, list->gr_name, list->size, list->date,
				list->file->d_name);
	}
	else
	{
		if (i == 0)
			printf("total %s\n", arg.cblocks);
		printf("%s %s %s  %s  %s %s %s -> %s\n", list->rights, list->nlink,
				list->usr_name, list->gr_name, list->size, list->date,
				list->file->d_name, list->link);
	}
	return (42);
}

void		ft_ls(t_elem *list, t_opt arg, int i)
{
	if (arg.r == 1)
	{
		while (list->next)
			list = list->next;
		while (list)
		{
			if (arg.l == 1)
				i = print_l(list, arg, i);
			else
				ls_easy(list, arg);
			list = list->prev;
		}
	}
	else
	{
		while (list)
		{
			if (arg.l == 1)
				i = print_l(list, arg, i);
			else
				ls_easy(list, arg);
			list = list->next;
		}
	}
}
