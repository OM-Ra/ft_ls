/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:00:32 by mdelphia          #+#    #+#             */
/*   Updated: 2019/06/18 16:00:35 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_put_and_free(t_dirlist **dirlist, t_flag_dir *flaglist,
				int *flag)
{
	flaglist->put_flag = 0;
	if (*dirlist)
	{
		(*dirlist) = ft_sort(dirlist, flaglist);
		ft_putres((*dirlist), flaglist, 0);
		ft_free_dirlist(*dirlist);
	}
	(*flag) = 1;
}

static int	ft_len_dirfile(char **mas)
{
	int		len_dirfile;
	size_t	i;

	i = 0;
	len_dirfile = 0;
	while (mas[i])
	{
		i++;
		len_dirfile++;
	}
	return (len_dirfile);
}

static void	ft_is_dir(t_dirlist *dirlist, t_flag_dir *fl)
{
	int		flag;
	int		len_dirfile;
	size_t	i;

	i = 0;
	flag = 0;
	len_dirfile = ft_len_dirfile(fl->dir_file);
	while (fl->dir_file[i])
	{
		if ((flag && !fl->r_big) || (len_dirfile > 1 && !flag &&
		fl->r_big) || (len_dirfile > 1 && !fl->r_big) || (fl->put_flag))
		{
			if (flag)
				ft_putchar('\n');
			ft_putstr(fl->dir_file[i]);
			ft_putstr(":\n");
		}
		else if (flag)
			ft_putchar('\n');
		if (fl->r_big)
			ft_flag_r(fl->dir_file[i++], fl);
		else
			dirlist = ft_onedir(fl->dir_file[i++], fl);
		ft_put_and_free(&dirlist, fl, &flag);
	}
}

static void	ft_nodir(t_flag_dir *flaglist)
{
	t_dirlist *dirlist;

	dirlist = NULL;
	if (flaglist->r_big)
	{
		if (ft_flag_r(".", flaglist))
			exit(1);
	}
	else if (!(dirlist = ft_onedir(".", flaglist)))
		exit(1);
	if (dirlist)
	{
		dirlist = ft_sort(&dirlist, flaglist);
		ft_putres(dirlist, flaglist, 0);
		ft_free_dirlist(dirlist);
	}
}

int			main(int ac, char **av)
{
	t_flag_dir	*flaglist;
	t_dirlist	*dirlist;
	int			line;

	dirlist = NULL;
	flaglist = NULL;
	if (!(flaglist = ft_sortdir(flaglist, ac, av, &line)))
		exit(1);
	if (flaglist->dir_file[0] && (ac - line))
		ft_is_dir(dirlist, flaglist);
	else if (ac < 2 || (!(flaglist->dir_file[0]) && !(ac - line)))
		ft_nodir(flaglist);
	ft_free_flaglist(flaglist);
	return (0);
}
