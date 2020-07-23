/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirrent_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:18:02 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/24 11:18:06 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct dirent	*ft_dirrent_write(DIR *ptr)
{
	struct dirent *dirlist;
	struct dirent *dir_buf;

	if (!(dir_buf = readdir(ptr)))
		return (NULL);
	if (!(dirlist = (struct dirent*)malloc(sizeof(struct dirent))))
		return (NULL);
	ft_strcpy(dirlist->d_name, dir_buf->d_name);
	dirlist->d_type = dir_buf->d_type;
	dirlist->d_ino = dir_buf->d_ino;
	dirlist->d_namlen = dir_buf->d_namlen;
	dirlist->d_reclen = dir_buf->d_reclen;
	dirlist->d_seekoff = dir_buf->d_seekoff;
	return (dirlist);
}
