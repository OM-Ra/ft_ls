/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirlist_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:03:49 by mdelphia          #+#    #+#             */
/*   Updated: 2019/06/24 15:03:51 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_dirlist	*ft_new(void)
{
	t_dirlist	*dirlist;

	if (!(dirlist = (t_dirlist *)malloc(sizeof(t_dirlist))))
		return (NULL);
	if (!(dirlist->buf_stat = (struct stat *)malloc(sizeof(struct stat))))
		return (NULL);
	dirlist->dirname = NULL;
	dirlist->grup = NULL;
	dirlist->pass = NULL;
	dirlist->maj_min = 0;
	dirlist->access = NULL;
	dirlist->link_way = NULL;
	dirlist->namefile = NULL;
	dirlist->left = NULL;
	dirlist->right = NULL;
	return (dirlist);
}

t_dirlist			*ft_dirlist_new(t_dirlist *list)
{
	t_dirlist	*dirlist;

	if (!(dirlist = ft_new()))
		exit(1);
	if (!list)
		return (dirlist);
	list->right = dirlist;
	dirlist->left = list;
	return (dirlist);
}
