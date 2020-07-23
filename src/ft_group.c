/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:13:38 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/24 11:13:40 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct group	*ft_group(gid_t gid)
{
	struct group *grup;
	struct group *buf_grup;

	if (!(grup = (struct group *)malloc(sizeof(struct group))))
		return (NULL);
	if (!(buf_grup = getgrgid(gid)))
		return (NULL);
	if (!(grup->gr_name = ft_strdup(buf_grup->gr_name)))
		return (NULL);
	grup->gr_gid = buf_grup->gr_gid;
	grup->gr_passwd = NULL;
	grup->gr_mem = NULL;
	return (grup);
}
