/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flag_L_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:42:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/02 19:42:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				f_flag_l_small_(t_get_file **a, t_ls *l)
{
	int			i;
	mode_t		val;

	i = 0;
	((l->r && l->t) || (l->t && !l->r)) ? f_time_order_(a, l) : 1;
	l->r ? f_order_a_z_r(a, l) : 0;
	!l->t && !l->r ? f_order_a_z_(a, l) : 0;
	ft_printf("total %d\n", l->st_block);
	while (i < a[0]->c_arg)
	{
		a[i]->f_name ? val = a[i]->m_st.st_mode : 1;
		a[i]->f_name ? o_g_p_permissions_(val) : 1;
		a[i]->f_name ? f_link_uid_gid_t_(a, l, i) : 1;
		i++;
	}
	ft_printf("\n");
	return (1);
}
