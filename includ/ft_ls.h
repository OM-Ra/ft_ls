/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:59:13 by mdelphia          #+#    #+#             */
/*   Updated: 2019/06/18 15:59:18 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <pwd.h>
# include <sys/types.h>
# include <time.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>
# include <sys/ioctl.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include <sys/sysmacros.h>

typedef struct			s_len
{
	int					len_grup;
	int					len_user;
	int					len_point;
	int					len_size;
	int					len_blocks;
	int					len_major;
	int					len_minor;
	int					m_putflag;
}						t_len;

typedef struct			s_dirlist
{
	struct dirent		*dirname;
	struct stat			*buf_stat;
	struct passwd		*pass;
	struct group		*grup;
	char				*access;
	char				*link_way;
	char				*namefile;
	int					maj_min;
	struct s_dirlist	*right;
	struct s_dirlist	*left;

}						t_dirlist;

typedef struct			s_flag_dir
{
	char				**dir_file;
	int					flag_line;

	int					r_big;
	int					l;
	int					r;
	int					a;
	int					t;
	int					one;
	int					m;
	int					s;
	int					g;
	int					g_flag;
	int					i_inode;
	int					o;
	int					o_flag;
	int					put_flag;

}						t_flag_dir;

t_dirlist				*ft_onedir(char *av, t_flag_dir *flaglist);
t_flag_dir				*ft_sortdir(t_flag_dir	*flaglist, int ac, char **av,
							int *flag_line);
t_dirlist				*ft_dirlist_new(t_dirlist *list);
int						ft_flag_r(char *namedir, t_flag_dir *flaglist);
void					ft_free_dirlist(t_dirlist *start);
int						ft_free_flaglist(t_flag_dir *start);
char					*ft_rights(t_dirlist *dirlist, char *name);
void					ft_putres(t_dirlist *start, t_flag_dir *flaglist,
							int er);
char					*ft_strtime(time_t mtime);
void					*ft_sort(t_dirlist **start, t_flag_dir *flaglist);
void					ft_write_flag_log(t_dirlist *list, t_flag_dir *flaglist,
							t_len len);
void					ft_lenelements(t_dirlist *start, t_len *len,
							t_flag_dir *flaglist);
void					ft_write_flag_si(t_dirlist *list, t_flag_dir *flaglist,
							t_len len);
void					ft_write_flag_other(t_dirlist *list,
							t_flag_dir *flaglist, t_len len);
int						ft_write_flags(t_flag_dir **flag_dir, char c);
t_dirlist				*ft_error_opendir(char *namefile, t_flag_dir *flaglist);
struct passwd			*ft_passwd_write(uid_t uid);
void					ft_write_maj_min(t_dirlist *list, t_flag_dir *flaglist,
							t_len len);
void					ft_put_flag_go(t_dirlist *list, t_flag_dir *flaglist,
							t_len len);
void					ft_sort_start_namedir(int ac, char **av, int line);
struct group			*ft_group(gid_t gid);
struct dirent			*ft_dirrent_write(DIR *ptr);
void					ft_onefile(int ac, char **namefile, t_flag_dir *fl);
int						ft_isfile_or_no(char *namefile);
void					ft_nextlist(t_dirlist **list, t_flag_dir **flaglist);
void					ft_put_permitionfile(int ac, char **av,
							t_flag_dir *flaglist);

#endif
