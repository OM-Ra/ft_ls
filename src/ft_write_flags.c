/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:14:12 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/17 11:14:15 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_error_flags(char c)
{
	int fd;

	fd = 2;
	ft_putstr_fd("ft_ls: illegal option -- ", fd);
	ft_putchar_fd(c, fd);
	ft_putstr_fd("\nusage: ft_ls [-Ragilmorst1] [file ...]\n", fd);
	return (1);
}

static void	ft_one(t_flag_dir **flag_dir)
{
	(*flag_dir)->one = 1;
	(*flag_dir)->m = 0;
	(*flag_dir)->l = 0;
	(*flag_dir)->o = 0;
	(*flag_dir)->g = 0;
}

static void	ft_m(t_flag_dir **flag_dir)
{
	(*flag_dir)->m = 1;
	(*flag_dir)->l = 0;
	(*flag_dir)->o = 0;
	(*flag_dir)->g = 0;
	(*flag_dir)->one = 0;
}

static void	ft_log(t_flag_dir **flag_dir, char c)
{
	if (c == 'l')
	{
		(*flag_dir)->l = 1;
		if ((*flag_dir)->g_flag)
			(*flag_dir)->g = 1;
		if ((*flag_dir)->o_flag)
			(*flag_dir)->o = 1;
	}
	else if (c == 'o')
	{
		(*flag_dir)->o = 1;
		(*flag_dir)->o_flag = 1;
		if ((*flag_dir)->g_flag)
			(*flag_dir)->g = 1;
	}
	else
	{
		(*flag_dir)->g = 1;
		(*flag_dir)->g_flag = 1;
		if ((*flag_dir)->o_flag)
			(*flag_dir)->o = 1;
	}
	(*flag_dir)->one = 0;
	(*flag_dir)->m = 0;
}

int			ft_write_flags(t_flag_dir **flag_dir, char c)
{
	if (c == 'R')
		(*flag_dir)->r_big = 1;
	else if (c == 'r')
		(*flag_dir)->r = 1;
	else if (c == 'l' || c == 'o' || c == 'g')
		ft_log(flag_dir, c);
	else if (c == 'm')
		ft_m(flag_dir);
	else if (c == '1')
		ft_one(flag_dir);
	else if (c == 'a')
		(*flag_dir)->a = 1;
	else if (c == 't')
		(*flag_dir)->t = 1;
	else if (c == 's')
		(*flag_dir)->s = 1;
	else if (c == 'i')
		(*flag_dir)->i_inode = 1;
	else
		return (ft_error_flags(c));
	return (0);
}
