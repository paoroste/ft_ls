/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:54:19 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/02 20:54:00 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_min(dev_t result)
{
	int		i;

	i = result;
	while ((i / 256) > 0)
		i = i / 256;
	return (i);
}

int		check_maj(dev_t result)
{
	int		a;

	a = result % 256;
	return (a);
}

int		check(int size)
{
	int		i;

	i = 0;
	while (size >= 10)
	{
		size = size / 10;
		i++;
	}
	return (i);
}

int		check_ma(t_elem *list)
{
	int		result;

	result = 0;
	while (list)
	{
		if (check_maj(list->fstat.st_rdev))
			result = check_maj(list->fstat.st_rdev);
		list = list->next;
	}
	return (result);
}

int		more_check(t_elem *tmp, int size)
{
	int		min;
	int		maj;

	min = 0;
	maj = 0;
	while (tmp)
	{
		if (check(check_min(tmp->fstat.st_rdev)) > min)
			min = check(check_min(tmp->fstat.st_rdev));
		if (check(check_maj(tmp->fstat.st_rdev)) > maj)
			maj = check(check_maj(tmp->fstat.st_rdev));
		tmp = tmp->next;
	}
	size = min + maj + 4;
	return (size);
}
