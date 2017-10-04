/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 19:34:22 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/03 12:50:48 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*put_rights(t_elem *tmp, char *str)
{
	char		*str2;

	str2 = ft_strdup("---------");
	if (tmp->fstat.st_mode & S_IRUSR)
		str2[0] = 'r';
	if (tmp->fstat.st_mode & S_IWUSR)
		str2[1] = 'w';
	if (tmp->fstat.st_mode & S_IXUSR)
		str2[2] = 'x';
	if (tmp->fstat.st_mode & S_IRGRP)
		str2[3] = 'r';
	if (tmp->fstat.st_mode & S_IWGRP)
		str2[4] = 'w';
	if (tmp->fstat.st_mode & S_IXGRP)
		str2[5] = 'x';
	if (tmp->fstat.st_mode & S_IROTH)
		str2[6] = 'r';
	if (tmp->fstat.st_mode & S_IWOTH)
		str2[7] = 'w';
	if (tmp->fstat.st_mode & S_IXOTH)
		str2[8] = 'x';
	return (ft_freejoin(str, str2, 3));
}

char		*get_rights(t_elem *tmp)
{
	if (S_ISREG(tmp->fstat.st_mode))
		return (ft_strdup("-"));
	if (S_ISDIR(tmp->fstat.st_mode))
		return (ft_strdup("d"));
	if (S_ISLNK(tmp->fstat.st_mode))
		return (ft_strdup("l"));
	if (S_ISCHR(tmp->fstat.st_mode))
		return (ft_strdup("c"));
	if (S_ISBLK(tmp->fstat.st_mode))
		return (ft_strdup("b"));
	if (S_ISFIFO(tmp->fstat.st_mode))
		return (ft_strdup("p"));
	if (S_ISSOCK(tmp->fstat.st_mode))
		return (ft_strdup("s"));
	return (ft_strdup("-"));
}

char		*good_aligned(char *name, int tmp)
{
	int			max;
	char		*final;

	final = (char*)malloc(sizeof(char) * (tmp + 1));
	final[tmp] = '\0';
	max = tmp;
	tmp = 0;
	while (name[tmp])
	{
		final[tmp] = name[tmp];
		tmp++;
	}
	while (tmp < max)
	{
		final[tmp] = ' ';
		tmp++;
	}
	free(name);
	return (final);
}

void		bad_aligned(t_elem *list, int usr, int grp)
{
	t_elem		*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->i != 0)
		{
			if (grp < ft_strlen(tmp->gr_name))
				grp = ft_strlen(tmp->gr_name);
			if (usr < ft_strlen(tmp->usr_name))
				usr = ft_strlen(tmp->usr_name);
		}
		tmp = tmp->next;
	}
	while (list)
	{
		if (list->i != 0)
		{
			list->gr_name = good_aligned(list->gr_name, grp);
			list->usr_name = good_aligned(list->usr_name, usr);
		}
		list = list->next;
	}
}

t_opt		get_more_info(t_elem *tmp, t_elem *list, t_opt arg)
{
	while (tmp)
	{
		if (tmp->i != 0)
		{
			if ((tmp->usr = getpwuid(tmp->fstat.st_uid)) == NULL)
				tmp->usr_name = ft_itoa(tmp->fstat.st_uid);
			else
				tmp->usr_name = ft_strdup(tmp->usr->pw_name);
			if ((tmp->group = getgrgid(tmp->fstat.st_gid)) == NULL)
				tmp->gr_name = ft_itoa(tmp->fstat.st_uid);
			else
				tmp->gr_name = ft_strdup(tmp->group->gr_name);
			tmp->rights = get_rights(tmp);
			tmp->rights = put_rights(tmp, tmp->rights);
			tmp->rights = more_rights(tmp, tmp->rights);
			arg.blocks = arg.blocks + tmp->fstat.st_blocks;
		}
		tmp = tmp->next;
	}
	arg.cblocks = itoa_long(arg.blocks);
	get_time_mm(list, arg, 0, 0);
	put_time(list);
	bad_aligned(list, 0, 0);
	return (arg);
}
