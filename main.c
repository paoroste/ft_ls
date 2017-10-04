/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:44:42 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/04 14:17:23 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			one_of(char c, char *str)
{
	int		i;

	i = 0;
	if ((str == NULL) || c == '\0')
		return (0);
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

t_opt		get_arg(t_opt arg, char *str)
{
	int i;

	i = 0;
	while (str[++i])
	{
		if (one_of(str[i], "-Ralrt") || (str[1] == '-' && !str[2]))
		{
			arg.up_r = (str[i] == 'R' ? 1 : arg.up_r);
			arg.a = (str[i] == 'a' ? 1 : arg.a);
			arg.l = (str[i] == 'l' ? 1 : arg.l);
			arg.r = (str[i] == 'r' ? 1 : arg.r);
			arg.t = (str[i] == 't' ? 1 : arg.t);
		}
		else
			error_arg(str[i]);
	}
	return (arg);
}

int			core(char *path, t_opt arg)
{
	DIR				*rep;
	t_elem			*list;
	struct dirent	*fichier;

	list = NULL;
	if ((rep = opendir(path)) == NULL)
		return (error("ft_ls: ", path, arg));
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	while ((fichier = readdir(rep)) != NULL)
		if (check_uni(fichier->d_name))
			list = get_info(list, fichier, path, arg);
	list = ft_ls_sort(list, arg);
	arg = get_more_info(list, list, arg);
	ft_ls(list, arg, 0);
	if (arg.up_r == 1)
		up_r(list, arg);
	closedir(rep);
	erase(list);
	free(arg.cblocks);
	free(path);
	return (0);
}

void		main2(char **av, int a, t_opt arg, int ac)
{
	DIR		*rep;

	if ((rep = opendir(av[a])) == NULL)
		errno == ENOTDIR ? 0 : 0;
	else if (a < ac && (a + 1) < ac)
	{
		ft_print("%s:\n", av[a]);
		arg.aff = 42;
		arg.path = av[a];
		core(ft_strdup(av[a]), arg);
		ft_print("\n", av[a]);
	}
	else if (a < ac && arg.c >= 1 && (a + 1) == ac)
	{
		ft_print("%s:\n", av[a]);
		arg.aff = 42;
		arg.path = av[a];
		core(ft_strdup(av[a]), arg);
	}
	else if ((a + 1) == ac)
		core(ft_strdup(av[a]), arg);
}

int			main(int argc, char **av)
{
	DIR			*rep;
	int			a;
	t_opt		arg;

	a = 1;
	arg = (t_opt){0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0};
	while (a < argc && av[a][0] == '-' && av[a][1] != '\0')
	{
		arg = get_arg(arg, av[a]);
		a++;
	}
	a == argc ? core(ft_strdup("./"), arg) : 0;
	error_unknow(argc, av, arg, a);
	av = arg_ascii(argc, av, arg, a);
	not_dir(argc, av, arg, a);
	while (a < argc)
	{
		main2(av, a, arg, argc);
		a++;
		arg.c = arg.c + 1;
	}
	return (0);
}
