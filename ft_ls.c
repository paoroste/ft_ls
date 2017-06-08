/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:44:31 by paoroste          #+#    #+#             */
/*   Updated: 2017/06/08 18:27:09 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_easy(t_opt arg, t_elem *file)
{
	t_elem *chem;

	chem = file;
	while (chem)
	{
		//if (!(arg.a == 0 && chem->name[0] == '.'))
		//{
			ft_putendl(chem->name);
		//}
		chem = chem->next;
	}
}
