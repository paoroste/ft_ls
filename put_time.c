/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:01:06 by paoroste          #+#    #+#             */
/*   Updated: 2017/09/30 19:03:08 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_nl(int nl, int nl2, char c)
{
	if (nl < nl2 && c == '.')
		return (nl2);
	return (nl);
}

char		*more_rights(t_elem *list, char *str)
{
	if ((list->fstat.st_mode & S_ISUID) && str[3] == 'x')
		str[3] = 's';
	if ((list->fstat.st_mode & S_ISUID) && str[3] == '-')
		str[3] = 'S';
	if ((list->fstat.st_mode & S_ISGID) && str[6] == 'x')
		str[6] = 's';
	if ((list->fstat.st_mode & S_ISGID) && str[6] == '-')
		str[6] = 'S';
	if ((list->fstat.st_mode & S_ISVTX) && str[9] == 'x')
		str[9] = 't';
	if ((list->fstat.st_mode & S_ISVTX) && str[9] == '-')
		str[9] = 'T';
	return (str);
}

char		*put_date(char *str)
{
	char		*final;

	final = (char*)malloc(sizeof(char) * 13);
	final[12] = '\0';
	final[0] = str[8];
	final[1] = str[9];
	final[2] = ' ';
	final[3] = str[4];
	final[4] = str[5];
	final[5] = str[6];
	final[6] = ' ';
	final[7] = str[11];
	final[8] = str[12];
	final[9] = str[13];
	final[10] = str[14];
	final[11] = str[15];
	return (final);
}

char		*date_year(char *str)
{
	char		*final;

	final = (char*)malloc(sizeof(char) * 13);
	final[12] = '\0';
	final[0] = str[8];
	final[1] = str[9];
	final[2] = ' ';
	final[3] = str[4];
	final[4] = str[5];
	final[5] = str[6];
	final[6] = ' ';
	final[7] = ' ';
	final[8] = str[20];
	final[9] = str[21];
	final[10] = str[22];
	final[11] = str[23];
	return (final);
}

void		put_time(t_elem *list)
{
	t_elem		*tmp;
	char		*str;
	char		*str2;
	time_t		now;

	tmp = list;
	while(tmp)
	{
		if (tmp->i != 0)
		{
			str = ft_strdup(ctime(&tmp->fstat.st_mtime));
			now = time(NULL);
			str2 = ft_strdup(ctime(&now));
			if (ft_strcmp(&str[20], &str[20]) != 0)
				tmp->date = date_year(str);
			else
				tmp->date = put_date(str);
			free(str);
			free(str2);
		}
		tmp = tmp->next;
	}
}
