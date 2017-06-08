/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:44:42 by paoroste          #+#    #+#             */
/*   Updated: 2017/06/08 13:22:25 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		whats_dat(char *str)
{
	if (str && str[0] == '-' && str[1])
		return (1);
	return (0);
}

void		get_arg(t_opt *arg, char *str)
{
	int i;

	i = 0;
	while (str[++i])
	{
		if (one_of(str[i], "1lRartf") || (str[1] == '-' && !str[2]))
		{
			arg->l = (str[i] == 'l' ? 1 : arg->l);
			arg->up_r = (str[i] == 'R' ? 1 : arg->up_r);
			arg->a = (str[i] == 'a' ? 1 : arg->a);
			arg->r = (str[i] == 'r' ? 1 : arg->r);
			arg->t = (str[i] == 't' ? 1 : arg->t);
			arg->f = (str[i] == 'f' ? 1 : arg->f);
		}
		else
			error_arg(str[i]);
	}
}

void		get_param(int nb, char **param, t_opt *arg, t_list **path)
{
	int		i;
	int		what;
	
	i = -1;
	what = 1;
	while (++i < nb)
	{
		if (whats_dat(param[i + 1]) == 0)
			what = 0;
		if (what == 1)
			get_arg(arg, param[i + 1]);
		else if (what == 0)
			ft_lstend(path, param[i + 1], ft_strlen(param[i + 1]));
	}
}

int		main(int argc, char **argv)
{
	t_list		*path;
	t_opt		arg;

	arg = (t_opt){0, 0, 0, 0, 0, 0};
	path = NULL;
	if (argc > 1)
		get_param(argc -1, argv, &arg, &path);
	if (path == NULL)
		path = ft_lstnew("./", ft_strlen("./"));
	core(arg, path, path->next != NULL ? 1 : 0);
	return (0);
}
