/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:06:10 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/11 14:06:13 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_strtime(time_t mtime)
{
	char	*str;
	char	*buf_time;
	char	*buf;
	time_t	time_nuw;

	time_nuw = time(NULL);
	buf_time = ctime(&mtime);
	if ((time_nuw - mtime > 15768000) || (time_nuw - mtime < -15768000))
	{
		if (!(str = ft_strnew(13)))
			return (NULL);
		buf = ft_strsub(buf_time, 4, 7);
		ft_strcat(str, buf);
		ft_strcat(str, " ");
		free(buf);
		buf = ft_strsub(buf_time, 20, 4);
		ft_strcat(str, buf);
		free(buf);
	}
	else
		str = ft_strsub(buf_time, 4, 12);
	return (str);
}
