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

static int 		f_print_only_files_(t_get_file **a, t_ls *l)
{
	int i;
	int j;

	l->r ? f_order_a_z_r(a, l) : f_order_a_z_(a, l);
	l->t ? f_time_order_(a, l) : 1;
	i = 0;
	j = 0;
	if (l->l)
	{
		while (i < a[0]->c_arg)
		{
			a[i]->d_name ? 0 : o_g_p_permissions_(a[i]->m_st.st_mode);
			a[i]->d_name ? 0 : f_link_uid_gid_t_(a, l, i) && printf("\n");
			i++;
		}
	}
	else
	{
		f_get_tty_width(a, l);
		while (!a[i]->d_name && !a[i]->f_name)
			i++;
		while (i < a[0]->c_arg && a[i]->d_name)
			i++;
		l->tmp = i;
		while (i < a[0]->c_arg && j < l->line)
		{
			l->c = 0;
			while (l->c < l->width)
			{
				!l->c ?
				(a[i]->d_name ? 0 : ft_printf("%-*s", a[0]->lng_name + 8, a[i]->f_name))
					  : (l->tmp + l->line < a[0]->c_arg && (l->tmp += l->line))
						? a[l->tmp]->d_name
						  ? 0 : ft_printf("%-*s", a[0]->lng_name + 8, a[l->tmp]->f_name) : 0;
				l->c++;
			}
			ft_printf("\n") && ++j && ++i;
			l->tmp = i;
		}
	}
	ft_printf("\n");
	if (!l->only_ls || l->r_b)
		return (1);
	exit(EXIT_SUCCESS);
}

int 			f_print_(t_get_file **a, t_ls *l)
{
	t_get_file			**rec_arr;
	int					i;

	i = 0;
	l->a_rgc = a[0]->c_arg;
	l->eror ? f_error_order_(l->eror, l) : 1;
	a[0]->c_arg > 1 ? 0 : f_permis_denied_(a, l);
	if(l->only_ls)
	{
		a = f_get_arg_in_print(a, a[l->i]->d_name, l);
		f_print_only_ls_(a, l);
	}
	if (a[0]->c_arg == 1 && l->dir_on)
	{
		a = f_get_arg_in_print(a, a[l->i]->d_name, l);
		!l->r_b ? f_print_only_ls_(a, l) : 0;
		exit(EXIT_SUCCESS);
	}
	f_print_only_files_(a, l);
	while (i < a[0]->c_arg)
	{
		a[i]->d_name ?
		(rec_arr = f_get_arg_in_print(rec_arr, a[i]->d_name, l)) && (l->ls = 1) : 0;
		(a[i]->d_name && !l->r_b) ? f_print_only_ls_(rec_arr, l) : 0;
		i++;
	}
	l->ls ? f_permis_denied_(a, l) : 1;
	return (1);
}