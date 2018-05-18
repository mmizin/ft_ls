//
// Created by Nikolay MIZIN on 4/17/18.
//

#ifndef FT_LS_H
# define FT_LS_H
# define FLAGS "lRrtan"
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RES	"\x1B[0m"


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



typedef struct					s_stat_name
{
	char 						*f_name;
	char 						*d_name;
	char 						*path_name;
	int 						c_arg;
	uintmax_t 					lng_name;
	uintmax_t 					lng_link;
	uintmax_t 					lng_uid;
	uintmax_t  					lng_gid;
	uintmax_t 					lng_maj;
	uintmax_t 					lng_siz_f;
	uintmax_t  					lng_min;
	struct stat					m_st;
}								t_get_file;

typedef struct					s_struct
{
	int							r;
	int							r_b;		/* Flag '-R' */
	int							l;
	int							n;
	int							a;
	int							t;
	int							ls;
	int							dot;
	int							d_dot;		/* double dot */
	int							dashs;		/* when we have 2_dash for file with '-' in name */
	int							i;
	int							st_block;
	int							j;
	unsigned short				width;
	int							line;
	int 						dir_on;
	int 						c;
	time_t 						t2;
	time_t 						t1;
	uid_t 						uid;
	gid_t						gid;
	u_int						maj;
	u_int						min;
	nlink_t						link;
	int							tmp;
	int							only_ls;
	int 						on_flag;	/* Have we some flags or not */
	int							a_rgc;
	char 						*res;
	char 						**spl;
	char						**eror;
	char						buf[PATH_MAX];
	ssize_t						bufsiz;
	char 						*fname;
	char 						*dname;
	struct stat					mystat;
	struct passwd				*s_uid;
	struct group				*s_gid;
	t_get_file					**t_arr;
}								t_ls;

t_get_file		**f_get_file_from_argv(char **argv, t_ls *l, t_get_file **a);
int				f_scmp(char *s1, char *s2);
int				f_ls_initialize(t_ls *lls, int argc);
int				f_ls_chk_argv(char **argv, t_ls *l);
int				f_reset_variabels(t_ls *lls);
char			*f_sdup(const char *s1);
int				f_slen(const char *s);
char			*f_jo_fr(char  *s1, char *s2, int i);
char			*ft_strchr(const char *s, int c);
void			*f_memalloc(size_t size);
void			f_bzero(void *s, size_t n);
int 			f_print_(t_get_file **a, t_ls *l);
t_get_file 		**f_get_arg_in_print(t_get_file **a, char *name, t_ls *l);
int 			f_count_files_in_print(char *name);
int 			f_print_only_ls_(t_get_file **a, t_ls *l);
int				f_flag_a_(t_get_file **a, t_ls *l);
int				f_flag_l_small_(t_get_file **a, t_ls *l);
int 			f_link_uid_gid_t_(t_get_file **a, t_ls *l, int i);
char    		**f_spl(char *str);
int 			f_order_a_z_(t_get_file **a, t_ls *l);
int 			f_order_a_z_r(t_get_file **a, t_ls *l);
int 			f_error_order_(char **b, t_ls *l);
int				f_time_order_(t_get_file **a, t_ls *l);
int				f_num_size(uintmax_t num, int base);
int 			f_ls_init_get_file_stru_(t_get_file **a, int i);
int				f_get_param_lng_(t_get_file **a, t_ls *l, int i,
									struct dirent *dp);
void			o_g_p_permissions_(mode_t val);
int 			f_initialize_flg(t_ls *l, char res);
int 			f_permis_denied_(t_get_file **a, t_ls *l);
int				f_get_tty_width(t_get_file **a, t_ls *l);
#endif
