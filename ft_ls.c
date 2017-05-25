/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:57:30 by paoroste          #+#    #+#             */
/*   Updated: 2017/05/22 19:27:15 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem		**ft_ls_sort(t_elem **files)
{
	int		i;
	char	*tmp;

	i = 0;
	while (**files != NULL)
	{
		if (ft_strcmp(file->name[i], file->name[i + 1]) > 0)
		{
			tmp = file->name[i];
			file->name[i] = file->name[i + 1];
			file->name[i + 1] = tmp;
			i = 1;
		}
		else
			i++;
	}
	return (files);
}

int        main(int argc, char **argv)
{
	DIR*			rep = NULL;
	struct	dirent*	fichier = NULL;
	t_elem			*file = NULL;
	t_elem			**final = NULL;

	rep = opendir("./");
	if (rep == NULL)
		perror("");
	if (argc == 2 && (ft_memcmp(argv[1], "-a", 2) == 0))
	{
		while ((fichier = readdir(rep)) != NULL)
		{
			file->name = fichier->d_name;
			ft_add(final, file);
		}
	}
	else
	{
		while ((fichier = readdir(rep)) != NULL)
		{
			if (fichier->d_name[0] != '.')
			{
				tmp = file;
				file->next = tmp;
				file->name = (fichier->d_name);
			}
		}
	}
	if (closedir(rep) == -1)
		exit(-1);
	return (0);
}
