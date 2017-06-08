/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:38:11 by paoroste          #+#    #+#             */
/*   Updated: 2017/06/07 15:29:23 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			one_of(char c, char *str)
{
	int		i;

	if((str == NULL) || c == '\0')
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}