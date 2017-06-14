/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:57:30 by paoroste          #+#    #+#             */
/*   Updated: 2017/06/14 14:21:07 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int        ls_cmp(t_elem *src1, t_elem *src2)
{
	return (ft_strcmp(src1->name, src2->name));
}

void		ls_swap(t_elem *a, t_elem *b)
{
	t_elem	*tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void		sort(t_elem **list, int (*do_cmp)(t_elem *src1, t_elem *src2))
{
	t_elem	*a;
	t_elem	*b;

	a = *list;
	while (a)
	{
		b = a->next;
		while (b)
		{
//			if (do_cmp(a, b) > 0)
//				ls_swap(a, b);
			b = b->next;
		}
		a = a->next;
	}
}

void		ls_tros(t_elem **list)
{
	t_elem	*x;
	t_elem	*y;
	t_elem	*z;

	x = *list;
	y = NULL;
	while (x)
	{
		z = y;
		y = x;
		x = x->next;
		y->next = z;
	}
	*list = y;
}

t_elem		*ft_ls_sort(t_elem **list, t_opt arg)
{
	t_elem		*to_sort;

	if (!list)
		return (NULL);
	to_sort = *list;
	if (arg.f == 0)
	{
		//sort(&to_sort, ls_cmp);
		arg.r == 1 ? ls_tros(&to_sort) : NULL;
	}
	return (to_sort);
}

/*void	dont_know()
{
	DIR*				rep = NULL;
	struct	dirent*		fichier = NULL;
	t_elem				*file = NULL;
	t_elem				**final = NULL;

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
}*/
