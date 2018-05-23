/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_files_from_argv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:11:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/26 10:11:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int 	f_ischr_isblk(t_get_file **a, int i)
{
	uintmax_t j;
	uintmax_t k;

	j = 0;
	k = 0;
	j = f_num_size((uintmax_t)(major(a[i]->m_st.st_rdev)), 10);
	k = f_num_size((uintmax_t)(minor(a[i]->m_st.st_rdev)), 10);
	a[0]->lng_maj = a[0]->lng_maj < j ? j : a[0]->lng_maj;
	a[0]->lng_min = a[0]->lng_min < k ? k : a[0]->lng_min;
	return (1);
}

static int	f_flag_n_(t_get_file **a, int i)
{
	uintmax_t j;
	uintmax_t k;

	j = 0;
	k = 0;
	j = f_num_size(getpwuid(a[i]->m_st.st_uid)->pw_uid, 10);
	k = f_num_size(getgrgid(a[i]->m_st.st_gid)->gr_gid, 10);
	a[0]->lng_uid = a[0]->lng_uid < j ? j : a[0]->lng_uid;
	a[0]->lng_gid = a[0]->lng_gid < k ? k : a[0]->lng_gid;
	return (1);
}

static int 		f_get_leng_of_argv_(t_get_file **a, t_ls *l)
{
	uintmax_t j;

	l->i = -1;
	while (++l->i < a[0]->c_arg)
	{
		j = f_slen(a[l->i]->f_name);
		a[0]->lng_name = a[0]->lng_name < j ? j : a[0]->lng_name;
		j = f_num_size((uintmax_t)a[l->i]->m_st.st_nlink, 10);
		a[0]->lng_link = a[0]->lng_link < j ? j : a[0]->lng_link;
		if (l->n)
			f_flag_n_(a, l->i);
		else
		{
			j = f_slen(getpwuid(a[l->i]->m_st.st_uid)->pw_name);
			a[0]->lng_uid = a[l->i]->lng_uid < j ? j : a[0]->lng_uid;
			j = f_slen(getgrgid(a[l->i]->m_st.st_gid)->gr_name);
			a[0]->lng_gid = a[0]->lng_gid < j ? j : a[0]->lng_gid;
		}
		j = f_num_size((uintmax_t)a[l->i]->m_st.st_size, 10);
		if (S_ISCHR(a[l->i]->m_st.st_mode) || S_ISBLK(a[l->i]->m_st.st_mode))
			f_ischr_isblk(a, l->i);
		else
			a[0]->lng_siz_f = a[0]->lng_siz_f < j ? j : a[0]->lng_siz_f;
	}
	return (1);
}

static int		f_part_one_(char **argv, t_ls *l, t_get_file **a)
{
	if (!lstat(l->only_ls ? "." : (*argv), &a[l->i]->m_st))
	{
		if (S_ISLNK(a[l->i]->m_st.st_mode))
		{
			stat(l->only_ls ? "." : (*argv), &a[l->i]->m_st);
			a[l->i]->f_name = f_sdup(l->only_ls ? "." : *argv);
		}
		else
		{
			a[l->i]->f_name = f_sdup(l->only_ls ? "." : *argv);
		}
		S_ISDIR(a[l->i]->m_st.st_mode) ? l->dir_on = 1 : 0;
		if (++l->i != l->c)
			a[l->i] = (t_get_file *)malloc(sizeof(t_get_file));
	}
	return (1);
}

t_get_file		**f_get_file_from_argv(char **argv, t_ls *l)
{
	t_get_file 	**a;
	char 		**tmp;

	tmp = argv;
	f_count_file(argv, l->a_rgc, l);
	l->c == 0 ? l->ls = 1 : 0;
	l->c == 0 ? (l->only_ls = 1) && ++l->c: 1;
	a = (t_get_file **)malloc(sizeof(t_get_file *) * l->c);
	a[0] = (t_get_file *)malloc(sizeof(t_get_file));
	a[0]->c_arg = l->c;
	while (l->i < l->c)
	{
		a[l->i]->path_name = l->ls ? f_sdup(".") : NULL;
		argv++;
		f_part_one_(argv, l, a);
	}
	f_ls_init_get_file_stru_(a, 0);
	f_get_leng_of_argv_(a, l);
	argv = tmp;
	return (a);
}
