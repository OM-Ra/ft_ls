/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_maj_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:19:45 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/22 12:19:49 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_len_spase_minor(t_len len)
{
	if (len.len_size > len.len_minor)
		return (len.len_size);
	else
		return (len.len_minor);
}

static void	ft_put_maj_min_size(t_dirlist *list, t_len len)
{
	if (list->access[0] == 'c' || list->access[0] == 'b')
	{
		ft_putspase(len.len_major - ft_lenint(major(list->buf_stat->st_rdev)));
		ft_putnbr((int)major(list->buf_stat->st_rdev));
		ft_putstr(", ");
		ft_putspase((ft_len_spase_minor(len) -
			ft_lenint(minor(list->buf_stat->st_rdev))));
		ft_putnbr((int)minor(list->buf_stat->st_rdev));
	}
	else
	{
		ft_putspase((len.len_major + ft_len_spase_minor(len) + 2) -
			ft_lenint(list->buf_stat->st_size));
		ft_putnbr((int)list->buf_stat->st_size);
	}
	ft_putchar(' ');
}

void		ft_write_maj_min(t_dirlist *list, t_flag_dir *flaglist, t_len len)
{
	if (flaglist->i_inode || flaglist->s)
		ft_write_flag_si(list, flaglist, len);
	ft_putstr(list->access);
	ft_putchar(' ');
	ft_putspase((len.len_point - ft_lenint(list->buf_stat->st_nlink)));
	ft_putnbr((int)list->buf_stat->st_nlink);
	ft_putchar(' ');
	ft_put_flag_go(list, flaglist, len);
	ft_putchar(' ');
	ft_put_maj_min_size(list, len);
	ft_putstr(ft_strtime(list->buf_stat->st_mtimespec.tv_sec));
	ft_putchar(' ');
	if (!list->namefile)
		ft_putstr(list->dirname->d_name);
	else
		ft_putstr(list->namefile);
	if (list->access[0] == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(list->link_way);
	}
	ft_putchar('\n');
}
