/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:07:46 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/27 14:47:10 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_findflag(int ac, char **av, t_flag_dir *flag_dir)
{
	int		line;
	size_t	i;

	line = 1;
	while (line < ac)
	{
		i = 1;
		if (av[line][0] != '-' || (av[line][0] == '-' && !av[line][1]))
			return (line);
		while (av[line][i])
		{
			if (ft_write_flags(&flag_dir, av[line][i]))
				return (ft_free_flaglist(flag_dir));
			i++;
		}
		line++;
	}
	return (line);
}

static int	ft_flag_write(int ac, t_flag_dir **flag_dir)
{
	size_t i;

	i = 0;
	if (!((*flag_dir) = (t_flag_dir *)malloc(sizeof(t_flag_dir))))
		return (1);
	if (!((*flag_dir)->dir_file = (char **)malloc(sizeof(char *) * (ac + 1))))
		return (1);
	while (i < ((size_t)ac + 1))
		(*flag_dir)->dir_file[i++] = NULL;
	(*flag_dir)->flag_line = 0;
	(*flag_dir)->l = 0;
	(*flag_dir)->r_big = 0;
	(*flag_dir)->r = 0;
	(*flag_dir)->a = 0;
	(*flag_dir)->t = 0;
	(*flag_dir)->one = 1;
	(*flag_dir)->m = 0;
	(*flag_dir)->s = 0;
	(*flag_dir)->g = 0;
	(*flag_dir)->g_flag = 0;
	(*flag_dir)->i_inode = 0;
	(*flag_dir)->o = 0;
	(*flag_dir)->o_flag = 0;
	(*flag_dir)->put_flag = 0;
	return (0);
}

static int	ft_write_dirname(t_flag_dir *flaglist, char **av, int ac, int line)
{
	DIR		*ptr;
	size_t	i;

	i = 0;
	while (line < ac)
	{
		errno = 0;
		ptr = opendir(av[line]);
		if ((!errno || errno == 13) && errno != 20)
		{
			if (!ft_isfile_or_no(av[line]) &&
					!(flaglist->dir_file[i++] = ft_strdup(av[line])))
			{
				if (i > 0)
					ft_freesplit(flaglist->dir_file, i);
				return (1);
			}
		}
		line++;
		if (ptr)
			closedir(ptr);
	}
	ft_onefile(ac, av, flaglist);
	return (0);
}

t_flag_dir	*ft_sortdir(t_flag_dir *flaglist, int ac, char **av, int *flag_line)
{
	int	line;
	DIR	*ptr;

	if (ft_flag_write(ac, &flaglist))
		exit(1);
	if ((line = ft_findflag(ac, av, flaglist)) < 0)
		return (NULL);
	(*flag_line) = line;
	flaglist->flag_line = line;
	ft_sort_start_namedir(ac, av, line);
	ft_put_permitionfile(ac, av, flaglist);
	while (line < ac)
	{
		errno = 0;
		if (!(ptr = opendir(av[line])) && errno != 13 && errno != 20)
			ft_error_opendir(av[line], flaglist);
		line++;
		if (ptr)
			closedir(ptr);
	}
	if (ft_write_dirname(flaglist, av, ac, (*flag_line)))
		return (NULL);
	return (flaglist);
}
