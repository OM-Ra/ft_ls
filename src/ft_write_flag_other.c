/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 15:13:01 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/15 15:13:03 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_flag_other(t_dirlist *list, t_flag_dir *flaglist, t_len len)
{
	ft_write_flag_si(list, flaglist, len);
	if (flaglist->m && len.m_putflag)
		ft_putstr(", ");
	if (!list->namefile)
		ft_putstr(list->dirname->d_name);
	else
		ft_putstr(list->namefile);
	if (flaglist->one)
		ft_putchar('\n');
	len.m_putflag = 1;
}
