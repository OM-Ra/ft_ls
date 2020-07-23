/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_flaglist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:18:08 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/03 16:18:10 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_free_mas_str(char **mas)
{
	size_t i;

	i = 0;
	while (mas[i])
	{
		free(mas[i]);
		i++;
	}
	free(mas);
}

int			ft_free_flaglist(t_flag_dir *start)
{
	ft_free_mas_str(start->dir_file);
	free(start);
	start = NULL;
	return (-1);
}
