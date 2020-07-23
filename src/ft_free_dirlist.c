/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dirlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:57:48 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/03 14:57:51 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_free_group(struct group *grup)
{
	free(grup->gr_name);
	free(grup);
}

static void	ft_free_pass(struct passwd *pass)
{
	free(pass->pw_class);
	free(pass->pw_dir);
	free(pass->pw_gecos);
	free(pass->pw_name);
	free(pass->pw_passwd);
	free(pass->pw_shell);
	free(pass);
}

void		ft_free_dirlist(t_dirlist *start)
{
	t_dirlist	*buflist;

	buflist = start;
	while (buflist)
	{
		start = buflist;
		if (buflist->dirname)
			free(buflist->dirname);
		if (buflist->buf_stat)
			free(buflist->buf_stat);
		if (buflist->pass)
			ft_free_pass(buflist->pass);
		if (buflist->grup)
			ft_free_group(buflist->grup);
		if (buflist->access)
			free(buflist->access);
		if (buflist->link_way)
			free(buflist->link_way);
		buflist = buflist->right;
		free(start);
		start = NULL;
	}
}
