/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:09:56 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/27 15:10:35 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_nextlist(t_dirlist **list, t_flag_dir **flaglist)
{
	if ((*flaglist)->r)
		(*list) = (*list)->left;
	else
		(*list) = (*list)->right;
}
