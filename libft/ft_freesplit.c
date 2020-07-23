/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:18:31 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/23 12:18:35 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freesplit(char **str)
{
	char **start;

	if (str)
	{
		start = str;
		while (*str)
		{
			ft_memdel((void **)str);
			++str;
		}
		free(start);
		start = NULL;
	}
}
