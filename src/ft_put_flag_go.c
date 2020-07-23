/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_go.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:37:33 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/22 12:37:36 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_flag_go(t_dirlist *list, t_flag_dir *flaglist, t_len len)
{
	if (!flaglist->o || !flaglist->g)
	{
		if (!flaglist->g)
		{
			ft_putstr(list->pass->pw_name);
			ft_putspase(len.len_user - ft_strlen(list->pass->pw_name));
			ft_putstr("  ");
		}
		if (!flaglist->o)
		{
			ft_putstr(list->grup->gr_name);
			ft_putspase(len.len_grup - ft_strlen(list->grup->gr_name));
			ft_putstr("  ");
		}
	}
	else
		ft_putstr("  ");
}
