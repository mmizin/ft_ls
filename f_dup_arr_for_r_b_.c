/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_dup_arr_for_r_b_.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:27:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/23 19:27:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

t_get_file		**f_makkok_(t_get_file **a)
{
	int 		i;
	t_get_file	**tmp;

	i = 0;
	tmp = (t_get_file **)malloc(sizeof(t_get_file *) * a[0]->c_arg);
	tmp[i] = (t_get_file *)malloc(sizeof(t_get_file));
	while (i < a[0]->c_arg)
	{
		tmp[i]->f_name = f_sdup(a[i]->f_name);
		tmp[i]->c_arg = a[i]->c_arg;
		tmp[i]->path_name = f_sdup(a[0]->path_name);
		tmp[i]->lng_name = a[i]->lng_name;
		tmp[i]->lng_link = a[i]->lng_link;
		tmp[i]->lng_uid = a[i]->lng_uid;
		tmp[i]->lng_gid = a[i]->lng_gid;
		tmp[i]->lng_maj = a[i]->lng_maj;
		tmp[i]->lng_siz_f = a[i]->lng_siz_f;
		tmp[i]->lng_min = a[i]->lng_min;
		tmp[i]->m_st = a[i]->m_st;
		if (++i != a[0]->c_arg)
			tmp[i] = (t_get_file *)malloc(sizeof(t_get_file));
	}
	return (tmp);
}
