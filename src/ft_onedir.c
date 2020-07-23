/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onedir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:46:01 by mdelphia          #+#    #+#             */
/*   Updated: 2019/06/18 17:46:04 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_dirlist	*ft_free_oll_list(t_dirlist **start, DIR **ptr)
{
	if ((*start))
		ft_free_dirlist((*start));
	if ((*ptr))
		closedir((*ptr));
	return (NULL);
}

static int			ft_write_stat_and_grup(t_dirlist *list, char *str)
{
	if ((lstat(str, list->buf_stat)) < 0)
	{
		free(str);
		return (1);
	}
	if (!(list->pass = ft_passwd_write(list->buf_stat->st_uid)))
	{
		free(str);
		return (1);
	}
	if (!(list->grup = ft_group(list->buf_stat->st_gid)))
	{
		free(str);
		return (1);
	}
	return (0);
}

static int			ft_writelist2(t_dirlist *list, t_flag_dir *fl, char *av)
{
	char	*str;
	char	*str_buf;

	if (av[0] == '/')
		str = ft_strjoin(av, "/");
	else if (!(str = ft_str3str("./", av, "/")))
		return (1);
	str_buf = str;
	if (!(str = ft_strjoin(str, list->dirname->d_name)))
		return (1);
	if (str_buf)
		free(str_buf);
	if (fl->l || fl->o || fl->g || fl->i_inode || fl->s)
		if (ft_write_stat_and_grup(list, str))
			return (1);
	if ((fl->l || fl->o || fl->g) && !(list->access = ft_rights(list, str)))
		return (1);
	if (list->access && (list->access[0] == 'c' || list->access[0] == 'b'))
		list->maj_min = 1;
	free(str);
	return (0);
}

static int			ft_writelist(t_dirlist *start, t_flag_dir *flaglist,
						DIR *ptr, char *av)
{
	t_dirlist	*list;
	t_dirlist	*buf;

	list = start;
	while ((list->dirname = ft_dirrent_write(ptr)))
	{
		if (ft_writelist2(list, flaglist, av))
			return (1);
		list = ft_dirlist_new(list);
	}
	buf = list;
	list = list->left;
	list->right = NULL;
	free(buf->dirname);
	free(buf->buf_stat);
	free(buf);
	return (0);
}

t_dirlist			*ft_onedir(char *av, t_flag_dir *flaglist)
{
	DIR			*ptr;
	t_dirlist	*start_dirlist;

	errno = 0;
	if (!(ptr = opendir(av)))
		return (ft_error_opendir(av, flaglist));
	if (!(start_dirlist = ft_dirlist_new(NULL)))
		exit(1);
	if (ft_writelist(start_dirlist, flaglist, ptr, av))
		return (ft_free_oll_list(&start_dirlist, &ptr));
	if (closedir(ptr))
		exit(1);
	return (start_dirlist);
}
