/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:16:28 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/03 18:32:42 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		up_r_s(t_elem *list, t_opt arg)
{
	if ((ft_strcmp(list->file->d_name, ".") != 0)
			&& (ft_strcmp(list->file->d_name, "..") != 0)
			&& (list->file->d_name[0] != '.'))
	{
		if (arg.aff == 42)
		{
			ft_print("\n%s", arg.path);
			ft_print("/");
			ft_print("%s:\n", &list->path[ft_strlen(arg.path)]);
			arg.blocks = 0;
			core(list->path, arg);
		}
		else
		{
			ft_print("\n%s:\n", list->path);
			arg.blocks = 0;
			core(list->path, arg);
		}
	}
}

void		up_r_a(t_elem *list, t_opt arg)
{
	if ((ft_strcmp(list->file->d_name, ".") != 0)
			&& (ft_strcmp(list->file->d_name, "..") != 0))
	{
		if (arg.aff == 42)
		{
			ft_print("\n%s", arg.path);
			ft_print("/");
			ft_print("%s:\n", &list->path[ft_strlen(arg.path)]);
			arg.blocks = 0;
			core(list->path, arg);
		}
		else
		{
			ft_print("\n%s:\n", list->path);
			arg.blocks = 0;
			core(list->path, arg);
		}
	}
}

void		up_r(t_elem *list, t_opt arg)
{
	if (arg.r == 1)
		while (list->next)
			list = list->next;
	while (list)
	{
		if (list->i != 0)
		{
			if (arg.a == 1 && S_ISDIR(list->fstat.st_mode))
				up_r_a(list, arg);
			else if (S_ISDIR(list->fstat.st_mode))
				up_r_s(list, arg);
		}
		if (arg.r == 1)
			list = list->prev;
		else
			list = list->next;
	}
}
