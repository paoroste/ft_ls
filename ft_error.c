/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:45:12 by paoroste          #+#    #+#             */
/*   Updated: 2017/07/05 18:58:04 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_arg(char arg)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("usage: ft_ls [-Ralrt] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

int		error(char *str, char *error, t_opt arg)
{
	if (arg.a == 1 || error[0] != '.')
	{
		ft_putstr_fd(str, 2);
		perror(error);
	}
	return (0);
	//if (nb)
	//	exit(EXIT_FAILURE);
}
