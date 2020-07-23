/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onefile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:08:43 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/24 11:08:45 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static struct dirent	*ft_onedl(struct dirent *dir_buf)
{
	struct dirent *dirlist;

	if (!(dirlist = (struct dirent *)malloc(sizeof(struct dirent))))
		return (NULL);
	ft_strcpy(dirlist->d_name, dir_buf->d_name);
	dirlist->d_type = dir_buf->d_type;
	dirlist->d_ino = dir_buf->d_ino;
	dirlist->d_namlen = dir_buf->d_namlen;
	dirlist->d_reclen = dir_buf->d_reclen;
	dirlist->d_seekoff = dir_buf->d_seekoff;
	return (dirlist);
}

static void				ft_writestr_and_ptr(char *namefile, DIR **ptr,
							char **str, size_t i)
{
	if (!i)
	{
		(*ptr) = opendir(".");
		free(*str);
		(*str) = namefile;
	}
	else if ((ft_strlen(namefile) - i) != ft_strlen(namefile))
	{
		ft_strncpy((*str), namefile, i + 1);
		(*ptr) = opendir((*str));
		(*str) = ft_strcpy((*str), &namefile[i + 1]);
	}
	else
	{
		free(*str);
		(*str) = namefile;
		(*ptr) = opendir(*str);
	}
}

static struct dirent	*ft_onedirentfile(char *namefile)
{
	char			*str;
	size_t			i;
	struct dirent	*dirlist;
	struct dirent	*dir_buf;
	DIR				*ptr;

	i = 0;
	ptr = NULL;
	if (!(str = ft_strnew(1024)))
		exit(1);
	while (namefile[i])
		i++;
	while (i && namefile[i] != '/')
		i--;
	ft_writestr_and_ptr(namefile, &ptr, &str, i);
	while (ptr && (dir_buf = readdir(ptr)))
		if (!ft_strcmp(dir_buf->d_name, str) && (dirlist = ft_onedl(dir_buf)))
			break ;
	if (ptr)
		closedir(ptr);
	if (str && str != namefile)
		free(str);
	return (dirlist);
}

static void				ft_put_only_file(char *namefile, t_flag_dir *flaglist)
{
	t_dirlist *list;

	if (!(list = ft_dirlist_new(NULL)))
		exit(1);
	list->namefile = namefile;
	list->dirname = ft_onedirentfile(namefile);
	lstat(namefile, list->buf_stat);
	list->pass = ft_passwd_write(list->buf_stat->st_uid);
	list->grup = ft_group(list->buf_stat->st_gid);
	if (flaglist->l || flaglist->o || flaglist->g)
		list->access = ft_rights(list, namefile);
	if (list->access && (list->access[0] == 'c' || list->access[0] == 'b'))
		list->maj_min = 1;
	ft_putres(list, flaglist, 20);
	if (list)
		ft_free_dirlist(list);
}

void					ft_onefile(int ac, char **namefile,
							t_flag_dir *flaglist)
{
	size_t	line;
	DIR		*ptr;
	int		flag;

	flag = 0;
	line = (size_t)flaglist->flag_line;
	while (line < (size_t)ac)
	{
		errno = 0;
		ptr = opendir(namefile[line]);
		if (errno == 20)
		{
			ft_put_only_file(namefile[line], flaglist);
			flag = 1;
		}
		line++;
		if (ptr)
			closedir(ptr);
	}
	if (flag && flaglist->dir_file[0])
		ft_putchar('\n');
}
