/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:57:30 by paoroste          #+#    #+#             */
/*   Updated: 2017/06/14 15:51:00 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		whatI_do(t_opt arg, t_elem *files, int fichierorrep)
{
	t_elem	*chem;

	chem = files;
	chem = ft_ls_sort(&chem, arg);
	ls_easy(arg, chem);
	if (fichierorrep == 1)
		error("FT_LS:", "can't -> multidir(whatI_do)", 0);
}

void		ls_file(t_opt arg, t_list *fichier)
{
	t_list		*chem;
	t_elem		*files;

	chem = fichier;
	files  = NULL;
	arg.a = 1;
	while (chem)
	{
		get_info(&files, chem->content, ".", arg);
		chem = chem->next;
	}
	if (files)
		whatI_do(arg, files, 0);
}

void		ls_rep2(t_opt arg, t_list *rep, int reps)
{

}

void		ls_rep(t_opt arg, t_list *rep, int reps)
{
	t_list	*chem;
	t_elem	*dir;

	chem = rep;
	dir = NULL;
	while (chem)
	{
		get_info2(&dir, chem->content, "", arg);
		chem = chem->next;
	}
}
	
void		core(t_opt arg, t_list *path, int reps)
{
	DIR*			dir;
	t_list			*rep;
	t_list			*chem;
	t_list			*fichier;

	rep = NULL;
	fichier = NULL;
	chem = path;
	while (chem)
	{
		if ((dir = opendir(chem->content)) == NULL)
			errno != ENOTDIR ? error("ft_ls: ", chem->content, 0) : 
				ft_lstend(&fichier, chem->content, chem->content_size);
		else
		{
			ft_lstend(&rep, chem->content, chem->content_size);
			if (closedir(dir) == -1)
				error("ft_ls: ", chem->content, 0);
		}
		chem = chem->next;
	}
	fichier ? ls_file(arg, fichier) : NULL;
	fichier && rep ? ft_putchar('\n') : NULL;
	if (reps == 1)
		error("FT_LS: ", "can't -> multidir(core)", 0);
	rep ? ls_rep(arg, rep, reps) : NULL;
}
