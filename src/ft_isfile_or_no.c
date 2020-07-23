/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile_or_no.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:38:06 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/24 14:38:09 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_free_and_puter(char **str)
{
	if (*str)
		free(*str);
	return (1);
}

static void	ft_closeptr(DIR **ptr, size_t *i)
{
	if (*ptr)
		closedir(*ptr);
	(*i)++;
}

int			ft_isfile_or_no(char *namefile)
{
	size_t	i;
	size_t	len;
	char	*str;
	DIR		*ptr;

	i = 0;
	len = ft_strlen(namefile);
	if (!(str = ft_strnew(1024)))
		exit(1);
	while (i < len)
	{
		errno = 0;
		while (namefile[i] && namefile[i] != '/')
			i++;
		if (!namefile[i])
			break ;
		if (namefile[i] == '/')
			ft_strncpy(str, namefile, i);
		ptr = opendir(str);
		if (errno == 13 && i < len)
			return (ft_free_and_puter(&str));
		ft_closeptr(&ptr, &i);
	}
	free(str);
	return (0);
}
