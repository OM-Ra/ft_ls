/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenelements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:04:50 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/15 13:04:52 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_checklen(t_dirlist **slist, t_len *len)
{
	t_dirlist	*list;
	size_t		buflen;

	list = (*slist);
	if ((size_t)len->len_point < (buflen = ft_lenint(list->buf_stat->st_nlink)))
		len->len_point = buflen;
	if ((size_t)len->len_size < (buflen = ft_lenint(list->buf_stat->st_size)))
		len->len_size = buflen;
	if ((size_t)len->len_user < (buflen = ft_strlen(list->pass->pw_name)))
		len->len_user = buflen;
	if ((size_t)len->len_grup < (buflen = ft_strlen(list->grup->gr_name)))
		len->len_grup = buflen;
	if ((size_t)len->len_blocks < (buflen =
			ft_lenint(list->buf_stat->st_blocks)))
		len->len_blocks = buflen;
	if ((size_t)len->len_major < (buflen =
			ft_lenint(major(list->buf_stat->st_rdev))))
		len->len_major = buflen;
	if ((size_t)len->len_minor < (buflen =
			ft_lenint(minor(list->buf_stat->st_rdev))))
		len->len_minor = buflen;
}

void		ft_lenelements(t_dirlist *start, t_len *len, t_flag_dir *flaglist)
{
	t_dirlist	*list;

	list = start;
	len->len_size = 0;
	len->len_point = 0;
	len->len_user = 0;
	len->len_grup = 0;
	len->len_blocks = 0;
	len->len_major = 0;
	len->len_minor = 0;
	len->m_putflag = 0;
	if (flaglist->l || flaglist->o || flaglist->g)
		while (list)
		{
			if (flaglist->a || list->dirname->d_name[0] != '.')
				ft_checklen(&list, len);
			list = list->right;
		}
}
