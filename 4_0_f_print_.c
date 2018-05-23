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

static int 		f_part_two_(t_get_file **a, t_ls *l)
{
	l->c = 0;
	while (l->c < l->width)
	{
		if (!l->c)
		{
			if (S_ISREG(a[l->i]->m_st.st_mode))
			{
				ft_printf("%-*s", a[0]->lng_name + 8, a[l->i]->f_name);
				free(a[l->i]->f_name);
				a[l->i]->f_name = NULL;
				ft_printf("\n");
			}
		}
		else if (l->tmp + l->line < a[0]->c_arg && (l->tmp += l->line))
		{
			if (S_ISREG(a[l->tmp]->m_st.st_mode))
			{
				ft_printf("%-*s", a[0]->lng_name + 8, a[l->tmp]->f_name);
				free(a[l->tmp]->f_name);
				a[l->tmp]->f_name = NULL;
				ft_printf("\n");
			}
		}
		l->c++;
	}
	S_ISREG(a[l->i]->m_st.st_mode) ? ft_printf("\n") : 0;
	++l->j && ++l->i;
	l->tmp = l->i;
	return (1);
}

static int 		f_part_one_(t_get_file **a, t_ls *l)
{
	int i;

	((l->r && l->t) || (l->t && !l->r)) ? f_time_order_(a, l) : 1;
	l->r && !l->t ? f_order_a_z_r(a, l) : 0;
	!l->t && !l->r ? f_order_a_z_(a, l) : 0;
	i = 0;
	if (l->l)
	{
		while (i < a[0]->c_arg)
		{
			S_ISDIR(a[i]->m_st.st_mode) ? l->dir_on = 1 : 0;
			S_ISREG(a[i]->m_st.st_mode) ? o_g_p_permissions_(a[i]->m_st.st_mode)
										: 0;
			S_ISREG(a[i]->m_st.st_mode) ? f_link_uid_gid_t_(a, l, i) : 0;
			i++;
		}
	}
	return (1);
}

static int 		f_print_only_files_(t_get_file **a, t_ls *l)
{
	f_part_one_(a, l);
	if (!l->l)
	{
		f_get_tty_width(a, l);
		while (l->i < l->a_rgc && l->j < l->line)
		{
			f_part_two_(a, l);
		}
		f_free_(a);
//		ft_printf("\n");    /* if no print files put \n fucking */
	}
	if (l->dir_on || l->r_b)
		return (1);
	else
	{
		free(a);
		exit(EXIT_SUCCESS);
	}
}

int 			f_print_(t_get_file **a, t_ls *l)
{
	t_get_file			**rec_arr;
	int					i;
	int 				tmp;

	i = 0;
	tmp = a[0]->c_arg;
	l->a_rgc = a[0]->c_arg;
	l->eror ? f_error_order_(l->eror, l) : 1;
	!l->ls ? f_print_only_files_(a, l) : 0;
	while (i < tmp)
	{
		if (S_ISDIR(a[i]->m_st.st_mode))
		{
			if ((rec_arr = f_get_arg_in_print(a[i]->f_name, l)))
			{
				!l->r_b ? f_print_only_ls_(rec_arr, l) : 0;
			}
		}
		i++;
	}
	free(a);
	return (1);
}