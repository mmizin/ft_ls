/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_only_ls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 10:04:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/29 10:04:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int 		f_part_one_(t_get_file ***a, t_ls *l)
{
	int		i;

	i = 0;
	f_error_order_(l->eror);
	l->r ? f_order_a_z_r(a, l) : f_order_a_z_(a, l);
	l->t ? f_time_order_(a, l) : 1;
	while (i < (*a)[0]->c_arg)
	{
		(*a)[i]->d_name ? l->dname = (*a)[i]->d_name : (l->dname = NULL);
		(*a)[i]->f_name ? l->fname = (*a)[i]->f_name : (l->fname = NULL);
		if (l->dname)
			(l->dname && (f_slen(l->dname) >= 8)) ? l->tmp = -16
												  : (l->tmp = -8);
		if (l->fname)
			(l->fname && (f_slen(l->fname) >= 8)) ? l->tmp = -16
												  : (l->tmp = -8);
		l->dname ? printf("%*s", l->tmp, l->dname)
				 : ((l->fname) && printf("%*s", l->tmp, l->fname));
		i++;
	}
	return (1);
}

int 			f_print_only_ls_(t_get_file ***a, t_ls *l)
{
	int i;

	i = 0;
	if (!l->only_ls)
	{
		if (l->dot || l->d_dot)
			printf("%s:\n", (*a)[0]->path_name);
		else if (!f_scmp(".", (*a)[i]->path_name)
				 && !f_scmp("..", (*a)[i]->path_name))
			printf("%s:\n", (*a)[0]->path_name);
	}
	l->a ? 0 : f_flag_a_(a, l);
	if (l->l)
		f_flag_l_small_(a, l);
	else
		f_part_one_(a, l);
	printf("\n\n");

	if (!l->only_ls && l->r_b)
		return (1);
	exit(EXIT_SUCCESS);
}
