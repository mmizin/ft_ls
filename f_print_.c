/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:29:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/27 20:29:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int 		f_print_only_files_(t_get_file ***a, t_ls *l)
{
	int i;

	f_error_order_(l->eror) && l->r ? f_order_a_z_r(a, l) : f_order_a_z_(a, l);
	l->t ? f_time_order_(a, l) : 1;
	i = 0;
	while (i < (*a)[0]->c_arg)
	{
		(*a)[i]->f_name ? l->fname = (*a)[i]->f_name : (l->fname = NULL);
		if (l->fname)
			(l->fname && (f_slen(l->fname) >= 8)) ? l->tmp = -16
												  : (l->tmp = -8);
		l->fname ? printf("%*s", l->tmp, l->fname) : 0;
		i++;
	}
	printf("\n\n");
	return (1);
}

int 			f_print_(t_get_file ***a, t_ls *l)
{
	t_get_file			**rec_arr;

	l->r ? f_order_a_z_r(a, l) : f_order_a_z_(a, l);
	l->a_rgc = (*a)[0]->c_arg;
	(l->only_ls) ? f_print_only_ls_(a, l) : 0;
	f_print_only_files_(a, l);
	while (l->i < (*a)[0]->c_arg)
	{
		l->a_rgc--;
		(*a)[l->i]->d_name ?
		(f_get_arg_in_print(&rec_arr, (*a)[l->i]->d_name, l)) : 0;
		((*a)[l->i]->d_name && !l->r_b) ? f_print_only_ls_(&rec_arr, l) : 0;
		l->i++;
	}
	return (1);
}