/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:44:42 by paoroste          #+#    #+#             */
/*   Updated: 2017/09/30 20:10:24 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			one_of(char c, char *str)
{
	int		i;

	i = 0;
	if((str == NULL) || c == '\0')
		return (0);
	while (str[++i])
		if(str[i] == c)
			return (1);
	return (0);
}

void		get_arg(t_opt *arg, char *str)
{
	int i;

	i = 0;
	while (str[++i])
	{
		if (one_of(str[i], "-Ralrt") || (str[1] == '-' && !str[2]))
		{
			arg->up_r = (str[i] == 'R' ? 1 : arg->up_r);
			arg->a = (str[i] == 'a' ? 1 : arg->a);
			arg->l = (str[i] == 'l' ? 1 : arg->l);
			arg->r = (str[i] == 'r' ? 1 : arg->r);
			arg->t = (str[i] == 't' ? 1 : arg->t);
		}
		else
			error_arg(str[i]);
	}
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
		list = get_info(list, fichier, path, arg);
	list = ft_ls_sort(list, arg);
	arg = get_more_info(list, arg);
	ft_ls(list, arg, 0);
	closedir(rep);
	erase(list);
	free(arg.cblocks);
	free(path);
	return (0);
}

int			main(int argc, char **argv)
{
	int			a;
	t_opt		arg;

	a = 1;
	arg = (t_opt){0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL};
	while (a < argc && argv[a][0] == '-' && argv[a][1] != '\0')
	{
		get_arg(&arg, argv[a]);
		a++;
	}
	if (a == argc)
		core(ft_strdup("./"), arg);
	else
		while (a < argc)
		{
			core(ft_strdup(argv[a]), arg);
			a++;
		}
	return (0);
}
