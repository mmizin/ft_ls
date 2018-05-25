/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_order_a_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:20:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/07 13:20:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	f_get_lng_a(t_get_file **a)
{
	int 		i;
	
	i = 1;
	while (i < a[0]->c_arg)
	{
		a[i]->c_arg = a[0]->c_arg;
		a[i]->lng_name = a[0]->lng_name;
		a[i]->lng_link = a[0]->lng_link;
		a[i]->lng_uid = a[0]->lng_uid;
		a[i]->lng_gid = a[0]->lng_gid;
		a[i]->lng_maj = a[0]->lng_maj;
		a[i]->lng_min = a[0]->lng_min;
		a[i]->lng_siz_f = a[0]->lng_siz_f;
		i++;
	}
	return (1);
}

static int	f_fnd_lst_nm(char *name1, char *name2)
{
	int i;

	i = 0;
		while (name1[i] && name2[i])
		{
			if (name1[i] > name2[i])
				return (0);
			else if (name1[i] < name2[i])
				return (1);
			else if (name1[i] == name2[i])
				i++;
		}
	if (!name2[i])
		return (0);
	return (1);
}

static int	f_check_(t_get_file **a, int size)
{
	t_get_file		*tmp;
	int				res;
	int 			i;
	char 			*name1;
	char 			*name2;


	i = 0;
	res = 1;
	while (i + 1 < size)
	{
		name1 = a[i]->f_name;
		name2 = a[i + 1]->f_name;

		if (!f_fnd_lst_nm(a[i]->f_name, a[i + 1]->f_name))
		{
			res = 0;
			tmp = a[i];
			a[i] = a[i + 1] ;
			a[i + 1] = tmp;
		}
		i++;
	}
	return (res);
}

int 			f_order_a_z_(t_get_file **a, t_ls *l)
{
	t_get_file		*tmp;
	int 			mid;
	int 			size;
	int 			i;
	char 			*name1;
	char 			*name2;

	l->tmp = 1;
	f_get_lng_a(a);
	size = a[0]->c_arg;
	while (!f_check_(a, size))
	{
		i = 0;
		mid = size/ 2;
		size -= 1;
		while (i < mid)
		{
			name1 = a[i]->f_name;
			name2 = a[size]->f_name;
			if (!f_fnd_lst_nm(a[i]->f_name, a[size]->f_name))
			{
				tmp = a[i];
				a[i] = a[size];
				a[size] = tmp;
				if (!f_fnd_lst_nm(a[i]->f_name, a[i + 1]->f_name))
				{
					tmp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = tmp;
				}
				if (!f_fnd_lst_nm(a[size - 1]->f_name, a[size]->f_name))
				{
					tmp = a[size - 1];
					a[size - 1] = a[size - 1];
					a[size - 1] = tmp;
				}
				if (i == mid)
				{
					if (!f_fnd_lst_nm(a[i - 1]->f_name, a[i]->f_name))
					{
						tmp = a[i - 1];
						a[i - 1]  = a[i];
						a[i] = tmp;
					}
				}
			}
			i++;
			size--;
		}
	}
	return (1);
}



