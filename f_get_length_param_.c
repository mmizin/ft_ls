/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_length_param_.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:56:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/08 19:56:00 by nmizin           ###   ########.fr       */
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

int			f_get_param_lng_(t_get_file **a, t_ls *l, int i, struct dirent *dp)
{
	uintmax_t j;
	uintmax_t k;

	j = 0;
	k = 0;
	j = f_slen(dp->d_name);
	a[0]->lng_name = a[0]->lng_name < j ? j : a[0]->lng_name;
	k = f_num_size((uintmax_t) a[i]->m_st.st_nlink, 10);
	a[0]->lng_link = a[0]->lng_link < k ? k : a[0]->lng_link;
	if (l->n)
		f_flag_n_(a, i);
	else
	{
		j = f_slen(getpwuid(a[i]->m_st.st_uid)->pw_name);
		k = f_slen(getgrgid(a[i]->m_st.st_gid)->gr_name);
		a[0]->lng_uid = a[i]->lng_uid < j ? j : a[0]->lng_uid;
		a[0]->lng_gid = a[0]->lng_gid < k ? k : a[0]->lng_gid;
	}
	j = f_num_size((uintmax_t)a[i]->m_st.st_size, 10);
	if (S_ISCHR(a[i]->m_st.st_mode) || S_ISBLK(a[i]->m_st.st_mode))
		f_ischr_isblk(a, i);
	else
		a[0]->lng_siz_f = a[0]->lng_siz_f < j ? j : a[0]->lng_siz_f;
	return (1);
}
