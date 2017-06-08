/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:45:12 by paoroste          #+#    #+#             */
/*   Updated: 2017/06/08 13:19:46 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_arg(char arg)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("usage: ft_ls [-Ralrt1] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	error(char *str, char *error, int nb)
{
	//ft_putstr_fd(str, 2);
	perror(error);
	if (nb)
		exit(EXIT_FAILURE);
}
