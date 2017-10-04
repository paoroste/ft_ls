/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:45:12 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/04 13:20:01 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_arg(char arg)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("\nusage: ft_ls [-Ralrt] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	error_unknow(int ac, char **av, t_opt arg, int a)
{
	DIR		*rep;

	while (a < ac)
	{
		if ((rep = opendir(av[a])) == NULL)
			errno == ENOENT ? error("ft_ls: ", av[a], arg) : 0;
		a++;
	}
}

int		error(char *str, char *error, t_opt arg)
{
	if (arg.a == 1 || error[0] != '.')
	{
		ft_putstr_fd(str, 2);
		perror(error);
	}
	return (0);
}
