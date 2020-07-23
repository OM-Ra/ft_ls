/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:44:07 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/30 14:44:09 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_swap_dirlist(t_dirlist *list_1, t_dirlist *list_2,
				t_dirlist **start)
{
	t_dirlist *buf;

	if ((*start) == list_1)
		(*start) = list_2;
	buf = list_1->left;
	if (buf)
		buf->right = list_2;
	buf = list_2->right;
	if (buf)
		buf->left = list_1;
	list_1->right = list_2->right;
	list_2->right = list_1;
	list_2->left = list_1->left;
	list_1->left = list_2;
}

static void	ft_startlist(t_dirlist **start, t_dirlist **list1,
				t_dirlist **list2, int *flag)
{
	(*list1) = (*start);
	(*list2) = (*list1)->right;
	(*flag) = 0;
}

static void	ft_sort_alpha(t_dirlist **start, t_flag_dir *flaglist)
{
	t_dirlist	*list1;
	t_dirlist	*list2;
	int			flag;

	flag = 1;
	while (flag)
	{
		ft_startlist(start, &list1, &list2, &flag);
		while (list2)
		{
			if ((!flaglist->t) || (flaglist->t &&
				list1->buf_stat->st_mtimespec.tv_sec ==
				list2->buf_stat->st_mtimespec.tv_sec))
				if (ft_strcmp(list1->dirname->d_name, list2->dirname->d_name) >
					0 && (++flag))
				{
					ft_swap_dirlist(list1, list2, start);
					list1 = list2;
					list2 = list1->right;
				}
			list1 = list1->right;
			list2 = list2->right;
		}
	}
}

static void	ft_sort_t(t_dirlist **start)
{
	t_dirlist	*list1;
	t_dirlist	*list2;
	int			flag;

	flag = 1;
	while (flag)
	{
		list1 = (*start);
		list2 = list1->right;
		flag = 0;
		while (list2)
		{
			if (list1->buf_stat->st_mtimespec.tv_sec <
				list2->buf_stat->st_mtimespec.tv_sec)
			{
				flag = 1;
				ft_swap_dirlist(list1, list2, start);
				list1 = list2;
				list2 = list1->right;
			}
			list1 = list1->right;
			list2 = list2->right;
		}
	}
}

void		*ft_sort(t_dirlist **start, t_flag_dir *flaglist)
{
	if (flaglist->t)
		ft_sort_t(start);
	ft_sort_alpha(start, flaglist);
	return (*start);
}
