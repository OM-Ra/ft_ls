/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_log.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:36:19 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/15 12:36:24 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_putnamefile(t_dirlist *list)
{
	if (!list->namefile)
		ft_putstr(list->dirname->d_name);
	else
		ft_putstr(list->namefile);
	if (list->access[0] == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(list->link_way);
	}
}

void		ft_write_flag_log(t_dirlist *list, t_flag_dir *flaglist, t_len len)
{
	char *buf;

	if (flaglist->i_inode || flaglist->s)
		ft_write_flag_si(list, flaglist, len);
	ft_putstr(list->access);
	ft_putchar(' ');
	ft_putspase((len.len_point - ft_lenint(list->buf_stat->st_nlink)));
	ft_putnbr((int)list->buf_stat->st_nlink);
	ft_putchar(' ');
	ft_put_flag_go(list, flaglist, len);
	ft_putspase((len.len_size - ft_lenint(list->buf_stat->st_size)));
	ft_putnbr((int)list->buf_stat->st_size);
	ft_putchar(' ');
	buf = ft_strtime(list->buf_stat->st_mtimespec.tv_sec);
	ft_putstr(buf);
	free(buf);
	ft_putchar(' ');
	ft_putnamefile(list);
	ft_putchar('\n');
}
