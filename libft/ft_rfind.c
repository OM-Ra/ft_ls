/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:39:36 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/12 11:39:39 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_rfind(char *line, char sym)
{
	size_t i;

	if (line)
	{
		i = ft_strlen(line);
		while (i)
		{
			if (line[i] == sym)
				return (i);
			--i;
		}
	}
	return ((line && line[i] == sym) ? 0 : -1);
}
