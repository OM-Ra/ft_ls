/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_permitionfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:58:31 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/28 14:58:36 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_put_close_file(char *namefile)
{
	int	fd;

	fd = 1;
	ft_putstr_fd("ft_ls: ", fd);
	ft_putstr_fd(namefile, fd);
	ft_putstr_fd(": Permission denied\n", fd);
}

void		ft_put_permitionfile(int ac, char **av, t_flag_dir *flaglist)
{
	DIR	*ptr;
	int	line;

	line = flaglist->flag_line;
	while (line < ac)
	{
		errno = 0;
		ptr = opendir(av[line]);
		if (errno == 13 && ft_isfile_or_no(av[line]))
			ft_put_close_file(av[line]);
		if (ptr)
			closedir(ptr);
		line++;
	}
}
