/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_opendir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:45:39 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/17 15:45:41 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_put_errno_2(char *namefile, int fd)
{
	ft_putstr_fd("ft_ls: ", fd);
	ft_putstr_fd(namefile, fd);
	ft_putstr_fd(": No such file or directory\n", fd);
}

t_dirlist	*ft_error_opendir(char *namefile, t_flag_dir *flaglist)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = 2;
	if (errno == 13)
	{
		ft_putstr_fd("ft_ls: ", fd);
		while (namefile[i])
			i++;
		while (i && namefile[i] != '/')
			i--;
		if (i)
			ft_putstr_fd(&namefile[i + 1], fd);
		else
			ft_putstr_fd(namefile, fd);
		ft_putstr_fd(": Permission denied\n", fd);
	}
	else if (errno == 2)
		ft_put_errno_2(namefile, fd);
	flaglist->put_flag = 1;
	return (NULL);
}
