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

static int 	f_ischr_isblk(t_get_file ***a, t_ls * l, int i)
{
	(*a)[0]->lng_maj = (*a)[i]->lng_maj
			  < f_num_size((uintmax_t)(major((*a)[i]->m_st.st_rdev)), 10)
			  ? f_num_size((uintmax_t)(major((*a)[i]->m_st.st_rdev)), 10)
			  : (*a)[0]->lng_maj;
	(*a)[0]->lng_min = (*a)[i]->lng_min
			  < f_num_size((uintmax_t)(minor((*a)[i]->m_st.st_rdev)), 10)
			  ? f_num_size((uintmax_t)(minor((*a)[i]->m_st.st_rdev)), 10)
			  : (*a)[0]->lng_min;
	return (1);
}

static int	f_flag_n_(t_get_file ***a, t_ls *l, int i)
{
	(*a)[0]->lng_uid = (*a)[i]->lng_uid
					   < f_num_size(getpwuid((*a)[i]->m_st.st_uid)->pw_uid, 10)
					   ? f_num_size(getpwuid((*a)[i]->m_st.st_uid)->pw_uid, 10)
					   : (*a)[0]->lng_uid;
	(*a)[0]->lng_gid = (*a)[i]->lng_gid
					   < f_num_size(getpwuid((*a)[i]->m_st.st_gid)->pw_gid, 10)
					   ? f_num_size(getpwuid((*a)[i]->m_st.st_uid)->pw_gid, 10)
					   : (*a)[0]->lng_gid;
	return (1);
}

int			f_get_param_lng_(t_get_file ***a, t_ls *l, int i, struct dirent *dp)
{
	(*a)[0]->lng_name = (*a)[i]->lng_name < f_slen(dp->d_name)
						? f_slen(dp->d_name) : (*a)[0]->lng_name;
	(*a)[0]->lng_link = (*a)[i]->lng_link
						< f_num_size((uintmax_t) (*a)[i]->m_st.st_nlink, 10)
						? f_num_size((uintmax_t) (*a)[i]->m_st.st_nlink, 10)
						: (*a)[0]->lng_link;
	(l->n) ? f_flag_n_(a, l, i) : 1;
	(*a)[0]->lng_uid = (*a)[i]->lng_uid <
					   f_slen(getpwuid((*a)[i]->m_st.st_uid)->pw_name)
					   ? f_slen(getpwuid((*a)[i]->m_st.st_uid)->pw_name)
					   : (*a)[0]->lng_uid;
	(*a)[0]->lng_gid = (*a)[i]->lng_gid <
					   f_slen(getgrgid((*a)[i]->m_st.st_gid)->gr_name)
					   ? f_slen(getgrgid((*a)[i]->m_st.st_gid)->gr_name)
					   : (*a)[0]->lng_gid;
	if (S_ISCHR((*a)[i]->m_st.st_mode) || S_ISBLK((*a)[i]->m_st.st_mode))
		f_ischr_isblk(a, l, i);
	else
		(*a)[0]->lng_siz_f = (*a)[0]->lng_siz_f
				  < f_num_size((uintmax_t)(*a)[i]->m_st.st_size, 10)
				  ? f_num_size((uintmax_t)(*a)[i]->m_st.st_size, 10)
				  : (*a)[0]->lng_siz_f;
	return (1);
}
