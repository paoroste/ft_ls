/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:44:31 by paoroste          #+#    #+#             */
/*   Updated: 2017/07/05 20:15:44 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_easy(t_elem *list, t_opt arg)
{
	if(list->i == 0)
		return (0);
	ft_print("%s, ", list->file->d_name);
	return (0);
}

void		ft_ls(t_elem *list, t_opt arg, int i)
{
	if (arg.r == 1)
	{
		while (list->next)
			list = list->next;
		while(list)
		{
			ls_easy(list, arg);
			list = list->prev;
		}
	}
	else
	{
		while(list)
		{
			ls_easy(list, arg);
			list = list->next;
		}
	}
}
