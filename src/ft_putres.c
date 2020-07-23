/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:33:14 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/08 13:33:18 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_total(t_dirlist *start, t_flag_dir *flaglist)
{
	t_dirlist	*list;
	int			total;

	total = 0;
	list = start;
	while (list)
	{
		if (flaglist->a || (list->dirname->d_name[0] != '.'))
			total += (int)list->buf_stat->st_blocks;
		list = list->right;
	}
	return (total);
}

static void	ft_put_total(t_dirlist *start, t_flag_dir *flaglist, int *flag)
{
	if ((*flag) && (flaglist->l || flaglist->o || flaglist->g))
	{
		ft_putstr("total ");
		ft_putnbr(ft_total(start, flaglist));
		ft_putchar('\n');
		(*flag) = 0;
	}
}

static int	ft_maj_min(t_dirlist *start, t_flag_dir *flaglist)
{
	t_dirlist *list;

	list = start;
	if (flaglist->l || flaglist->o || flaglist->g)
	{
		while (list)
		{
			if (list->maj_min)
				return (1);
			list = list->right;
		}
	}
	return (0);
}

static void	ft_put_flag(int flag_majmin, t_dirlist *list,
				t_flag_dir *flaglist, t_len len)
{
	if (flaglist->l || flaglist->o || flaglist->g)
	{
		if (flag_majmin)
			ft_write_maj_min(list, flaglist, len);
		else
			ft_write_flag_log(list, flaglist, len);
	}
	else
		ft_write_flag_other(list, flaglist, len);
}

void		ft_putres(t_dirlist *start, t_flag_dir *flaglist, int er)
{
	t_dirlist	*list;
	t_len		len;
	int			flag;
	int			flag_majmin;

	list = start;
	flag = 1;
	flaglist->put_flag = 0;
	flag_majmin = ft_maj_min(start, flaglist);
	ft_lenelements(start, &len, flaglist);
	if (flaglist->r)
		while (list->right)
			list = list->right;
	while (list)
	{
		if (flaglist->a || (list->dirname->d_name[0] != '.'))
		{
			if (er != 20)
				ft_put_total(start, flaglist, &flag);
			ft_put_flag(flag_majmin, list, flaglist, len);
		}
		ft_nextlist(&list, &flaglist);
	}
	if (flaglist->m && len.m_putflag)
		ft_putchar('\n');
}
