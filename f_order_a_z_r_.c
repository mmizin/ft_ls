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

static	int		f_lcomp(char *one, char *two, t_ls *l)
{
	if (two && one)
	{
		while (*one && *two)
		{
			if (*one < *two)
				return (1);
			if (*one > *two)
				return (2);
			one++;
			two++;
		}
		if (*two)
			if (l->r)
				return (1);
	}
	return (0);
}

static int 		f_part_one_(t_get_file **a, t_get_file *arr, int *i)
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
		a[*i]->lng_siz_f = a[*i + 1]->lng_siz_f;
	}
	*i = 0;
	return (1);
}

int 			f_order_a_z_r(t_get_file **a, t_ls *l)
{
	int				i;
	int 			tmp;
	char			*one;
	char 			*two;
	t_get_file		*arr;

	arr = NULL;
	i = 0;
	tmp = a[0]->c_arg;
	while (i < tmp -1)
	{
		one = a[i]->f_name;
		if (i + 1 != tmp)
			two = a[i + 1]->f_name;
		else
			two = NULL;
		if (two && (f_lcomp(one, two, l)) == 2)
			i++;
		else if ((f_lcomp(one, two, l)) == 1)
			f_part_one_(a, arr, &i);
		else
			i++;
	}
	return (1);
}