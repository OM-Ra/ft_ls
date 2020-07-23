/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_start_namedir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:00:29 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/22 14:00:32 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_start_namedir(int ac, char **av, int line)
{
	char	*buf;
	int		flag;
	int		start_line;

	flag = 1;
	start_line = line;
	av[ac] = NULL;
	while (flag)
	{
		flag = 0;
		line = start_line;
		while (av[line + 1] && av[line])
		{
			if ((ft_strcmp(av[line], av[line + 1])) > 0)
			{
				flag = 1;
				buf = av[line];
				av[line] = av[line + 1];
				av[line + 1] = buf;
			}
			line++;
		}
	}
}
