/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_time_order_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 07:45:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/19 07:45:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				f_reverse_time_(t_get_file **a)
{
	t_get_variables		v;
	t_get_file			*tmp;

	v.i = 0;
	v.j = a[0]->c_arg - 1;
	while (v.i < v.j)
	{
		tmp = a[v.i];
		a[v.i] = a[v.j];
		a[v.j] = tmp;
		if (v.i == 0)
		{
			a[v.i]->c_arg = a[v.j]->c_arg;
			a[v.i]->lng_name = a[v.j]->lng_name;
			a[v.i]->lng_link = a[v.j]->lng_link;
			a[v.i]->lng_uid = a[v.j]->lng_uid;
			a[v.i]->lng_gid = a[v.j]->lng_gid;
			a[v.i]->lng_maj = a[v.j]->lng_maj;
			a[v.i]->lng_min = a[v.j]->lng_min;
			a[v.i]->lng_min = a[v.j]->lng_min;
		}
		v.i++;
		v.j--;
	}
	return (1);
}

static int		f_part_one_(t_get_file **a, t_get_file *arr, int *i)
{
	arr = a[*i];
	a[*i] = a[*i + 1];
	a[*i + 1] = arr;
	if (*i == 0)
	{
		a[*i]->c_arg = a[*i + 1]->c_arg;
		a[*i]->lng_name = a[*i + 1]->lng_name;
		a[*i]->lng_link = a[*i + 1]->lng_link;
		a[*i]->lng_uid = a[*i + 1]->lng_uid;
		a[*i]->lng_gid = a[*i + 1]->lng_gid;
		a[*i]->lng_maj = a[*i + 1]->lng_maj;
		a[*i]->lng_min = a[*i + 1]->lng_min;
		a[*i]->lng_min = a[*i + 1]->lng_min;
	}
	*i = 0;
	return (1);
}

int				f_time_order_(t_get_file **a, t_ls *l)
{
	int			i;
	int			tmp;
	t_get_file	*arr;

	arr = NULL;
	i = 0;
	tmp = a[0]->c_arg;
	while (i < tmp - 1)
	{
		l->t1 = a[i]->m_st.st_mtimespec.tv_sec;
		l->t2 = a[i + 1]->m_st.st_mtimespec.tv_sec;
		if (l->t2 > l->t1)
			f_part_one_(a, arr, &i);
		else
			i++;
	}
	return (1);
}
