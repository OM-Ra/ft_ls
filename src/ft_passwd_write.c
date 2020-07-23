/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_passwd_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 11:09:20 by mdelphia          #+#    #+#             */
/*   Updated: 2019/08/18 11:09:22 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct passwd	*ft_passwd_write(uid_t uid)
{
	struct passwd *passlist;
	struct passwd *pass_buf;

	if (!(pass_buf = getpwuid(uid)))
		return (NULL);
	if (!(passlist = (struct passwd*)malloc(sizeof(struct passwd))))
		return (NULL);
	passlist->pw_change = pass_buf->pw_change;
	passlist->pw_expire = pass_buf->pw_expire;
	passlist->pw_gid = pass_buf->pw_gid;
	passlist->pw_uid = pass_buf->pw_uid;
	passlist->pw_gecos = ft_strdup(pass_buf->pw_gecos);
	passlist->pw_shell = ft_strdup(pass_buf->pw_shell);
	passlist->pw_passwd = ft_strdup(pass_buf->pw_passwd);
	passlist->pw_name = ft_strdup(pass_buf->pw_name);
	passlist->pw_dir = ft_strdup(pass_buf->pw_dir);
	passlist->pw_class = ft_strdup(pass_buf->pw_class);
	if (!passlist->pw_gecos || !passlist->pw_shell || !passlist->pw_passwd ||
		!passlist->pw_name || !passlist->pw_dir || !passlist->pw_class)
		return (NULL);
	return (passlist);
}
