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

static	int		f_ischr_isblk(t_get_file **a, int i)
{
	uintmax_t j;
	uintmax_t k;

	j = f_num_size((uintmax_t)(major(a[i]->m_st.st_rdev)), 10);
	k = f_num_size((uintmax_t)(minor(a[i]->m_st.st_rdev)), 10);
	a[0]->lng_maj = a[0]->lng_maj < j ? j : a[0]->lng_maj;
	a[0]->lng_min = a[0]->lng_min < k ? k : a[0]->lng_min;
	return (1);
}

static int		f_flag_n_(t_get_file **a, int i)
{
	uintmax_t j;
	uintmax_t k;

	j = f_num_size(getpwuid(a[i]->m_st.st_uid)->pw_uid, 10);
	k = f_num_size(getgrgid(a[i]->m_st.st_gid)->gr_gid, 10);
	a[0]->lng_uid = a[0]->lng_uid < j ? j : a[0]->lng_uid;
	a[0]->lng_gid = a[0]->lng_gid < k ? k : a[0]->lng_gid;
	return (1);
}

static void		f_get_leng_of_argv_(t_get_file **a, t_ls *l)
{
	uintmax_t		j;
	t_get_variables v;

	f_initialize_var(&v) && (v.i = -1);
	while (++v.i < a[0]->c_arg)
	{
		j = f_slen(a[v.i]->f_name);
		a[0]->lng_name = a[0]->lng_name < j ? j : a[0]->lng_name;
		j = f_num_size((uintmax_t)a[v.i]->m_st.st_nlink, 10);
		a[0]->lng_link = a[0]->lng_link < j ? j : a[0]->lng_link;
		if (l->n)
			f_flag_n_(a, v.i);
		else
		{
			j = f_slen(getpwuid(a[v.i]->m_st.st_uid)->pw_name);
			a[0]->lng_uid = a[v.i]->lng_uid < j ? j : a[0]->lng_uid;
			j = f_slen(getgrgid(a[v.i]->m_st.st_gid)->gr_name);
			a[0]->lng_gid = a[0]->lng_gid < j ? j : a[0]->lng_gid;
		}
		j = f_num_size((uintmax_t)a[v.i]->m_st.st_size, 10);
		if (S_ISCHR(a[v.i]->m_st.st_mode) || S_ISBLK(a[v.i]->m_st.st_mode))
			f_ischr_isblk(a, v.i);
		else
			a[0]->lng_siz_f = a[0]->lng_siz_f < j ? j : a[0]->lng_siz_f;
	}
}

static int		f_part_one_(char **argv, t_ls *l, t_get_file ***a,
												t_get_variables *v)
{
	if (!lstat(l->ls ? "." : argv[v->i], &l->l_st))
	{
		(*a)[v->j] = (t_get_file *)malloc(sizeof(t_get_file));
		lstat(l->ls ? "." : argv[v->i], &(*a)[v->j]->m_st);
		(*a)[v->j]->c_arg = v->c;
		(*a)[v->j]->path_name = NULL;
		(*a)[v->j]->f_name = f_sdup(l->ls ? "." : argv[v->i]);
		v->j++;
	}
	return (1);
}

t_get_file		**f_get_file_from_argv(char **argv, t_ls *l)
{
	t_get_file		**a;
	t_get_variables	v;

	f_initialize_var(&v);
	v.c = f_count_file(argv, l->a_rgc, l);
	v.c == 0 && !l->eror ? l->ls = 1 : 0;
	v.c == 0 && !l->eror ? (l->ls = 1) && ++v.c : 1;
	if (!v.c && l->eror)
	{
		f_error_order_(l->eror, l);
		exit(EXIT_SUCCESS);
	}
	a = (t_get_file **)malloc(sizeof(t_get_file *) * v.c);
	while (v.i < l->a_rgc)
	{
		++v.i;
		f_part_one_(argv, l, &a, &v);
		if (l->ls)
			break ;
	}
	f_initialize_lng(a, 0);
	f_get_leng_of_argv_(a, l);
	return (a);
}
