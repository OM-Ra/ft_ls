/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:42:14 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/02 12:42:18 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_putdirname(char *namedir)
{
	static int a;

	if (namedir && a)
	{
		ft_putstr(namedir);
		ft_putstr(":\n");
	}
	a = 1;
}

static void	ft_recurs(t_dirlist *dirlist, t_flag_dir *flaglist, char *namedir)
{
	char *str;

	if (dirlist->dirname->d_type == DT_DIR &&
		!(dirlist->dirname->d_name[0] == '.' && (!dirlist->dirname->d_name[1] ||
		(dirlist->dirname->d_name[1] == '.' && !dirlist->dirname->d_name[2]))))
		if (flaglist->a || (dirlist->dirname->d_name[0] != '.'))
		{
			ft_putchar('\n');
			if (((namedir[0] != '/') || (namedir[0] == '/' && namedir[1])) &&
				!(str = ft_str3str(namedir, "/", dirlist->dirname->d_name)))
				exit(1);
			else if (namedir[0] == '/' && !namedir[1])
				str = ft_strjoin(namedir, dirlist->dirname->d_name);
			ft_flag_r(str, flaglist);
			free(str);
		}
}

int			ft_flag_r(char *namedir, t_flag_dir *flaglist)
{
	t_dirlist		*dirlist;
	t_dirlist		*startlist;

	ft_putdirname(namedir);
	if (!(dirlist = ft_onedir(namedir, flaglist)))
		return (1);
	ft_sort(&dirlist, flaglist);
	ft_putres(dirlist, flaglist, 0);
	startlist = dirlist;
	if (flaglist->r)
		while (dirlist->right)
			dirlist = dirlist->right;
	while (dirlist)
	{
		ft_recurs(dirlist, flaglist, namedir);
		ft_nextlist(&dirlist, &flaglist);
	}
	ft_free_dirlist(startlist);
	return (0);
}
