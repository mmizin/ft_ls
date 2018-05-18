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

static int 		f_part_one_(t_get_file **a, t_ls *l)
{
	int i;

	i = 0;
	l->j = 0;
	f_get_tty_width(a, l);
	while (i < a[0]->c_arg && !a[i]->d_name && !a[i]->f_name)
		i++;
	l->tmp = i;
	while (i < a[0]->c_arg && l->j < l->line)
	{
		l->c = 0;
		while (l->c < l->width)
		{
			if (!l->c)
			{
				a[i]->d_name ?
				ft_printf("%-*s", a[0]->lng_name + 8, a[i]->d_name) : 0;
				a[i]->f_name ?
				ft_printf("%-*s", a[0]->lng_name + 8, a[i]->f_name) : 0;
			}
			else if (l->tmp + l->line < a[0]->c_arg && (l->tmp += l->line))
			{
				a[l->tmp]->d_name ?
				ft_printf("%-*s", a[0]->lng_name + 8, a[l->tmp]->d_name) : 0;
				a[l->tmp]->f_name ?
				ft_printf("%-*s", a[0]->lng_name + 8, a[l->tmp]->f_name) : 0;
			}
				l->c++;
		}
		ft_printf("\n") && ++l->j && ++i;
		l->tmp = i;
	}
	return (1);
}

int 			f_print_only_ls_(t_get_file **a, t_ls *l)
{
	int i;

	i = f_slen(a[0]->path_name);
	if ((f_scmp("./", a[0]->path_name) && (!l->dot || !l->d_dot))
		|| (f_scmp("../", a[0]->path_name) && (!l->dot || !l->d_dot)))
		;
	else if (!l->only_ls || (a[0]->c_arg == 1 && l->dir_on) || l->r_b)
	{
		a[0]->path_name[i - 1] == '/'
		? ft_printf("%.*s:\n", i - 1, a[0]->path_name)
		: ft_printf("%s:\n", a[0]->path_name);
	}
	l->r ? f_order_a_z_r(a, l) : f_order_a_z_(a, l);
	l->a ? 0 : f_flag_a_(a, l);
//	l->eror ? f_error_order_(l->eror, l) : 1;
	l->t ? f_time_order_(a, l) : 1;
	if (l->l)
		f_flag_l_small_(a, l);
	else
		f_part_one_(a, l);
	if (!l->only_ls || l->r_b)
		return (1);
	exit(EXIT_SUCCESS);
}
