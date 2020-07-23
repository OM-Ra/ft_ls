/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_si.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 15:20:37 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/15 15:20:38 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_flag_si(t_dirlist *list, t_flag_dir *flaglist, t_len len)
{
	if (flaglist->i_inode)
	{
		ft_putnbr((int)list->buf_stat->st_ino);
		ft_putchar(' ');
	}
	if (flaglist->s)
	{
		ft_putspase(len.len_blocks - ft_lenint(list->buf_stat->st_blocks));
		ft_putnbr((int)list->buf_stat->st_blocks);
		ft_putchar(' ');
	}
}
