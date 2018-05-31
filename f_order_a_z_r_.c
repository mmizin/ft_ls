/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_order_a_z_r_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 07:51:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/19 07:51:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	f_get_lng_a(t_get_file **a)
{
	int		i;

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
			return (1);
		else if (name1[i] < name2[i])
			return (0);
		else if (name1[i] == name2[i])
			i++;
	}
	if (ft_strlen(name1) < ft_strlen(name2))
		return (0);
	return (1);
}

static int	f_check_(t_get_file **a, int size)
{
	t_get_file		*tmp;
	int				res;
	int				i;

	i = 0;
	res = 1;
	while (i + 1 < size)
	{
		if (!f_fnd_lst_nm(a[i]->f_name, a[i + 1]->f_name))
		{
			res = 0;
			tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
		}
		i++;
	}
	return (res);
}

int			f_order_a_z_r(t_get_file **a)
{
	int				size;

	f_get_lng_a(a);
	size = a[0]->c_arg;
	while (!f_check_(a, size))
		;
	return (1);
}
