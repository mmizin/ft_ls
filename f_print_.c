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

static int		f_part_two_(t_get_file **a, t_ls *l, t_get_variables *v)
{
	while (v->c < l->width)
	{
		S_ISDIR(a[v->tmp]->m_st.st_mode) ? l->dir_on = 1 : 0;
		if (!v->c)
		{
			if (S_ISREG(a[v->i]->m_st.st_mode))
				ft_printf("%-*s", a[0]->lng_name + 8, a[v->i]->f_name)
				&& ++v->k;
		}
		else if (v->tmp + l->line < a[0]->c_arg && (v->tmp += l->line))
		{
			S_ISDIR(a[v->tmp]->m_st.st_mode) ? l->dir_on = 1 : 0;
			if (S_ISREG(a[v->tmp]->m_st.st_mode))
				ft_printf("%-*s", a[0]->lng_name + 8, a[v->tmp]->f_name)
				&& ++v->k;
		}
		v->c++;
	}
	l->dir_on && v->k ? ft_printf("\n\n") : ft_printf("\n");
	!v->k ? ft_printf(UP"") : 0;
	++v->j && ++v->i;
	v->tmp = v->i;
	return (1);
}

static int		f_part_one_(t_get_file **a, t_ls *l)
{
	int			i;

	l->file_on = 0;
	i = 0;
	if (l->l)
	{
		while (i < a[0]->c_arg)
		{
			S_ISDIR(a[i]->m_st.st_mode) ? l->dir_on = 1 : 0;
			S_ISREG(a[i]->m_st.st_mode) ? o_g_p_permissions_(a[i]->m_st.st_mode)
										: 0;
			S_ISREG(a[i]->m_st.st_mode) ?
						f_link_uid_gid_t_(a, l, i) && ++l->file_on : 0;
			i++;
		}
		l->dir_on && l->file_on ? ft_printf("\n") : 0;
	}
	return (1);
}

static int		f_print_only_files_(t_get_file **a, t_ls *l)
{
	t_get_variables v;

	f_initialize_var(&v);
	!l->f && l->t ? f_time_order_(a, l) : 1;
	!l->f && l->r && !l->t ? f_order_a_z_r(a) : 0;
	!l->f && !l->t && !l->r ? f_order_a_z_(a) : 0;
	!l->f && l->t && l->r ? f_reverse_time_(a) : 0;
	l->l ? f_part_one_(a, l) : 0;
	if (!l->l)
	{
		f_get_tty_width(a, l);
		while (v.i < l->a_rgc && v.j < l->line)
		{
			f_part_two_(a, l, &v);
		}
	}
	if (l->dir_on || l->r_b || S_ISLNK(a[0]->m_st.st_mode))
	{
		return (1);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

int				f_print_(t_get_file **a, t_ls *l)
{
	t_get_file			**rec_arr;
	t_get_variables		v;

	f_initialize_var(&v);
	v.tmp = a[0]->c_arg;
	l->a_rgc = a[0]->c_arg;
	l->eror ? f_error_order_(l->eror, l) : 1;
	l->d ? f_print_ls_(a, l) : 0;
	!l->ls ? f_print_only_files_(a, l) : 0;
	while (v.i < v.tmp)
	{
		if (S_ISLNK(a[v.i]->m_st.st_mode) && l->l)
			f_print_ls_(a, l);
		else if (S_ISDIR(a[v.i]->m_st.st_mode) || S_ISLNK(a[v.i]->m_st.st_mode))
		{
			if ((rec_arr = f_get_arg_in_print(a[v.i]->f_name, l)))
			{
				!l->r_b ? f_print_ls_(rec_arr, l) : 0;
				f_free_(rec_arr);
			}
		}
		v.i++;
	}
	ft_printf(UP"");
	return (1);
}
