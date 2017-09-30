/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:31:53 by paoroste          #+#    #+#             */
/*   Updated: 2017/09/30 18:56:29 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*itoa_long(long long nb)
{
	int			i;
	char		*str;
	long long	tmp;

	i = 0;
	tmp = nb;
	while(nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (i + 1))))
		return (0);
	str[i + 1] = '\0';
	nb = tmp;
	while(i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

char		*conversion(long long size, int i)
{
	char	*str;
	int		s;

	s = 0;
	i++;
	str = (char*)malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (0);
	str[i + 1] = '\0';
	while(i >= 0)
	{
		str[i] = (size % 10) + '0';
		size = size / 10;
		i--;
	}
	while(str[s] == '0' && str[s + 1] != '\0')
	{
		str[s] = ' ';
		s++;
	}
	return (str);
}

char		*conversion2(int mineur, char *size, int ma)
{
	int		i;

	i = ft_strlen(size);
	i = i - (ma + 4);
	size[i + 1] = ' ';
	if (mineur == 0)
		size[i] = '0';
	else
		while (mineur > 0)
		{
			size[i] = (mineur % 10) + '0';
			mineur = mineur / 10;
			i--;
		}
	return (size);
}

void		get_time_mm2(t_elem *list, int size, int nl)
{
	int		ma;
	t_elem	*tmp;

	tmp = list;
	ma = check_ma(list);
	while (tmp)
	{
		if (tmp->i != 0 && tmp->rights[0] != 'c' && tmp->rights[0] != 'b')
		{
			tmp->size = conversion(tmp->fstat.st_size, (size - 1));
			tmp->nlink = conversion(tmp->fstat.st_nlink, nl);
		}
		if (tmp->i != 0 && (tmp->rights[0] == 'c' || tmp->rights[0] == 'b'))
		{
			tmp->nlink = conversion(tmp->fstat.st_nlink, nl);
			tmp->size = conversion(check_maj(tmp->fstat.st_rdev), (size - 1));
			tmp->size = conversion2(check_min(tmp->fstat.st_rdev), tmp->size, check(ma));
		}
		tmp = tmp->next;
	}
}

void		get_time_mm(t_elem *list, t_opt arg, int size, int nl)
{
	t_elem		*tmp;

	tmp = list;
	while(tmp)
	{
		if (tmp->i && (tmp->rights[0] == 'c' || tmp->rights[0] == 'b'))
			size = more_check(list, size);
		if (arg.a == 1 && tmp->i != 0)
		{
			if (check(tmp->fstat.st_size) > size)
				size = check(tmp->fstat.st_size);
			if (check(tmp->fstat.st_nlink > nl))
				nl = check(tmp->fstat.st_nlink);
		}
		else if (tmp->i != 0)
		{
			if (check(tmp->fstat.st_size) > size && tmp->file->d_name[0] != '.')
				size = check(tmp->fstat.st_size);
			nl = check_nl((check(tmp->fstat.st_nlink)), nl, tmp->file->d_name[0] != '.')
		}
		tmp = tmp->next;
	}
	get_time_mm2(list, size, nl);
}
