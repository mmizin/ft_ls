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

static int		f_part_two__(t_get_file **a, t_get_variables *v, t_ls *l)
{
	v->c = 0;
	while (v->c < l->width)
	{
		if (!v->c)
		{
			ft_printf("%-*s", a[0]->lng_name + 8, a[v->i]->f_name);
		}
		else if (v->tmp + l->line < a[0]->c_arg && (v->tmp += l->line))
		{
			ft_printf("%-*s", a[0]->lng_name + 8, a[v->tmp]->f_name);
		}
		v->c++;
	}
	ft_printf("\n") && ++v->j && ++v->i;
	v->tmp = v->i;
	return (1);
}

static int		f_part_one__(t_get_file **a, t_ls *l)
{
	t_get_variables v;

	f_initialize_var(&v);
	!l->f && l->t ? f_time_order_(a, l) : 1;
	!l->f && l->r && !l->t ? f_order_a_z_r(a) : 0;
	!l->f && !l->t && !l->r ? f_order_a_z_(a) : 0;
	!l->f && l->t && l->r ? f_reverse_time_(a) : 0;
	f_get_tty_width(a, l);
	v.tmp = v.i;
	while (v.i < a[0]->c_arg && v.j < l->line)
		f_part_two__(a, &v, l);
	if (l->ls && !l->r_b)
	{
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int				f_print_ls_(t_get_file **a, t_ls *l)
{
	int i;

	i = f_slen(a[0]->path_name);
	if ((f_scmp(".", a[0]->path_name) && (!l->dot || !l->d_dot))
		|| (f_scmp("..", a[0]->path_name) && (!l->dot || !l->d_dot))
		|| f_scmp("/", a[0]->path_name))
		;
	else if ((!l->d && !l->ls && l->a_rgc != 1 && a[0]->path_name)
					|| (l->r_b && a[0]->path_name))
	{
		a[0]->path_name[i - 1] == '/'
		? ft_printf("%.*s:\n", i - 1, a[0]->path_name)
		: ft_printf("%s:\n", a[0]->path_name);
	}
	if (l->l)
		f_flag_l_small_(a, l);
	else
		f_part_one__(a, l);
	ft_printf("\n");
	if ((!l->d && !l->ls) || l->r_b)
		return (1);
	ft_printf(UP"");
	exit(EXIT_SUCCESS);
}
