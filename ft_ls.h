/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 23:26:43 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/30 23:26:48 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define FLAGS "lRrtan1Afd"
# define UP	"\033[1A"
# include <dirent.h>
# include "nmizin_printf/ft_printf.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <langinfo.h>
# include <stdint.h>
# include <string.h>
# include <fcntl.h>
# include <assert.h>
# include <curses.h>
# include <limits.h>
# include <zconf.h>
# include <sys/ioctl.h>

typedef struct					s_variables
{
	int							i;
	int							j;
	int							k;
	int							c;
	int							tmp;
	char						*ptr1;
	char						*ptr2;
}								t_get_variables;

typedef struct					s_stat_name
{
	char						*f_name;
	char						*path_name;
	int							c_arg;
	uintmax_t					lng_name;
	uintmax_t					lng_link;
	uintmax_t					lng_uid;
	uintmax_t					lng_gid;
	uintmax_t					lng_maj;
	uintmax_t					lng_siz_f;
	uintmax_t					lng_min;
	struct stat					m_st;
}								t_get_file;

typedef struct					s_struct
{
	t_get_variables				var;
	int							r;
	int							r_b;
	int							l;
	int							one;
	int							n;
	int							d;
	int							a;
	int							f;
	int							a_b;
	int							t;
	int							ls;
	int							dot;
	int							d_dot;
	int							dash;
	int							st_block;
	unsigned short				width;
	int							line;
	int							file_on;
	int							dir_on;
	time_t						t2;
	time_t						t1;
	uid_t						uid;
	gid_t						gid;
	u_int						maj;
	u_int						min;
	nlink_t						link;
	int							flag_on;
	int							a_rgc;
	char						*res;
	char						**spl;
	char						**eror;
	char						buf[PATH_MAX];
	ssize_t						bufsiz;
	struct stat					l_st;
	struct passwd				*s_uid;
	struct group				*s_gid;
	struct dirent				*dp;
}								t_ls;

int								f_print_ls_(t_get_file **a, t_ls *l);
int								f_flag_l_small_(t_get_file **a, t_ls *l);
int								f_link_uid_gid_t_(t_get_file **a, t_ls *l,
								int i);
void							o_g_p_permissions_(mode_t val);
int								f_permis_denied_(char *name, t_ls *l);
int								f_ls_chk_ar(char **argv, t_ls *l);
t_get_file						**f_get_file_from_argv(char **ar, t_ls *l);
int								f_print_(t_get_file **a, t_ls *l);
int								f_initialize_var(t_get_variables *ls);
int								f_initialize_ls(t_ls *lls, int argc);
int								f_initialize_lng(t_get_file **a, int i);
int								f_initialize_flg(t_ls *l, char res);
int								f_free_(t_get_file **a);
int								f_order_a_z_(t_get_file **a);
int								f_order_a_z_r(t_get_file **a);
int								f_reverse_time_(t_get_file **a);
int								f_time_order_(t_get_file **a, t_ls *l);
int								f_error_order_(char **b, t_ls *l);
char							**f_spl(char *str);
char							*f_jo_fr(char *s1, char *s2, int i);
int								f_scmp(char *s1, char *s2);
char							*f_sdup(const char *s1);
int								f_slen(const char *s);
char							*ft_strchr(const char *s, int c);
void							f_bzero(void *s, size_t n);
int								f_num_size(uintmax_t num, int base);
int								f_get_param_lng_(t_get_file **a, t_ls *l,
								int i, struct dirent *dp);
int								f_get_tty_width(t_get_file **a, t_ls *l);
int								f_count_files_in_print(char *name, t_ls *l);
int								f_count_file(char **argv, int argc, t_ls *l);
t_get_file						**f_get_arg_in_print(char *name, t_ls *l);
char							**f_fill_arr_error_(char **ar, t_ls *l,
								t_get_variables v);

#endif
