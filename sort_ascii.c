/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:11:49 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/04 17:16:21 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_date(time_t now, time_t mtime)
{
	if ((now - mtime) > 15724800)
		return (1);
	if (mtime > now)
		return (1);
	return (0);
}

void		not_dir(int ac, char **av, t_opt arg, int a)
{
	DIR		*rep;
	int		b;
	int		dir;

	b = 0;
	dir = 0;
	while (a < ac)
	{
		if ((rep = opendir(av[a])) != NULL)
			dir++;
		if ((rep = opendir(av[a])) == NULL)
		{
			if (errno == ENOTDIR)
			{
				ft_putstr_fd(av[a], 1);
				ft_putchar_fd('\n', 1);
				b++;
			}
		}
		a++;
	}
	if (b >= 1 && dir > 0)
		ft_putchar_fd('\n', 1);
}

char		**reverse_ascii(int ac, char **av, int a)
{
	char	*tmp;
	int		i;

	tmp = av[a];
	i = a;
	while (a < ac - 1)
	{
		if (ft_strcmp(av[a], av[a + 1]) < 0)
		{
			tmp = av[a];
			av[a] = av[a + 1];
			av[a + 1] = tmp;
			a = i;
		}
		else
			a++;
	}
	return (av);
}

char		**arg_ascii(int ac, char **av, t_opt arg, int a)
{
	DIR		*rep;
	char	*tmp;
	int		i;

	tmp = av[a];
	i = a;
	if (arg.r == 1)
		return (reverse_ascii(ac, av, a));
	while (a < ac - 1)
	{
		if (ft_strcmp(av[a], av[a + 1]) > 0)
		{
			tmp = av[a];
			av[a] = av[a + 1];
			av[a + 1] = tmp;
			a = i;
		}
		else
			a++;
	}
	return (av);
}
