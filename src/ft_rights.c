/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rights.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:45:53 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/05 15:45:55 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_xattr(char *namefile, char *str)
{
	acl_t	acl;
	ssize_t	xattr_len;

	acl = acl_get_link_np(namefile, ACL_TYPE_EXTENDED);
	xattr_len = listxattr(namefile, NULL, 0, XATTR_NOFOLLOW);
	if (xattr_len > 0)
		*str = '@';
	else if (acl)
		*str = '+';
	else
		*str = ' ';
	if (acl)
		free(acl);
}

static void	ft_writeaccess(int bool, char **str, char c, int flag)
{
	if (!flag)
	{
		if (bool)
			**str = c;
		else
			**str = '-';
		if (c != 'x')
			(*str)++;
	}
	else
	{
		if (bool)
		{
			if (**str == 'x')
				**str = c;
			else
				**str = (c - 32);
		}
		(*str)++;
	}
}

static void	ft_access(mode_t st_mode, char *str)
{
	char	*pstr;

	pstr = str;
	ft_writeaccess((st_mode & S_IRUSR), &pstr, 'r', 0);
	ft_writeaccess((st_mode & S_IWUSR), &pstr, 'w', 0);
	ft_writeaccess((st_mode & S_IXUSR), &pstr, 'x', 0);
	ft_writeaccess((st_mode & S_ISUID), &pstr, 's', 1);
	ft_writeaccess((st_mode & S_IRGRP), &pstr, 'r', 0);
	ft_writeaccess((st_mode & S_IWGRP), &pstr, 'w', 0);
	ft_writeaccess((st_mode & S_IXGRP), &pstr, 'x', 0);
	ft_writeaccess((st_mode & S_ISGID), &pstr, 's', 1);
	ft_writeaccess((st_mode & S_IROTH), &pstr, 'r', 0);
	ft_writeaccess((st_mode & S_IWOTH), &pstr, 'w', 0);
	ft_writeaccess((st_mode & S_IXOTH), &pstr, 'x', 0);
	ft_writeaccess((st_mode & S_ISVTX), &pstr, 't', 1);
}

static char	ft_typefile(uint8_t d_type)
{
	char c;

	if (d_type == DT_REG)
		c = '-';
	else if (d_type == DT_DIR || d_type == DT_UNKNOWN)
		c = 'd';
	else if (d_type == DT_LNK)
		c = 'l';
	else if (d_type == DT_CHR)
		c = 'c';
	else if (d_type == DT_BLK)
		c = 'b';
	else if (d_type == DT_FIFO)
		c = 'p';
	else if (d_type == DT_SOCK)
		c = 's';
	else
		c = 'D';
	return (c);
}

char		*ft_rights(t_dirlist *dirlist, char *name)
{
	char	*str;
	size_t	i;
	char	*buf[10241];

	i = 0;
	if (!(str = ft_strnew(11)))
		exit(1);
	str[i++] = ft_typefile((dirlist->dirname->d_type));
	ft_access(dirlist->buf_stat->st_mode, (&str[i]));
	ft_xattr(name, &str[10]);
	if (str[0] == 'l')
	{
		i = readlink(name, (char *)buf, 10240);
		if (!(dirlist->link_way = ft_strnew(i)))
			exit(1);
		i = readlink(name, dirlist->link_way, i);
		dirlist->link_way[i] = '\0';
	}
	return (str);
}
