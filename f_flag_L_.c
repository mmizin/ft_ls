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

void		o_g_p_permissions_(mode_t val)
{
	S_ISLNK(val) ? ft_printf("l") : 1 && S_ISREG(val) ? ft_printf("-") : 1;
	S_ISDIR(val) ? ft_printf("d") : 1 && S_ISCHR(val) ? ft_printf("c") : 1;
	S_ISBLK(val) ? ft_printf("b") : 1 && S_ISFIFO(val) ? ft_printf("p") : 1;
	S_ISSOCK(val) ? ft_printf("s") : 1;
	(val & S_IRUSR) ? ft_printf("r") : ft_printf("-");
	(val & S_IWUSR) ? ft_printf("w") : ft_printf("-");
	if ((val & S_ISUID) && !(val & S_IXUSR))
		ft_printf("S");
	else
		((val & S_ISUID) && (val & S_IXUSR))
		? ft_printf("s") : (val & S_IXUSR) ? ft_printf("x") : ft_printf("-");
	(val & S_IRGRP) ? ft_printf("r") : ft_printf("-");
	(val & S_IWGRP) ? ft_printf("w") : ft_printf("-");
	if ((val & S_ISGID) && !(val & S_IXGRP))
		ft_printf("S");
	else
		((val & S_ISGID) && (val & S_IXGRP))
		? ft_printf("s") : (val & S_IXGRP) ? ft_printf("x") : ft_printf("-");
	(val & S_IROTH) ? ft_printf("r") : ft_printf("-");
	(val & S_IWOTH) ? ft_printf("w") : ft_printf("-");
	if (val & S_ISVTX && !(val & S_IXOTH))
		ft_printf("T");
	else
		(val & S_ISVTX) ? ft_printf("t") : (val & S_IXOTH)
										? ft_printf("x") : ft_printf("-");
}

int				f_flag_l_small_(t_get_file **a, t_ls *l)
{
	int			i;
	mode_t		val;

	i = 0;
	l->r ? f_order_a_z_r(a, l) : f_order_a_z_(a, l);
	l->a ? 0 : f_flag_a_(a, l);
//	l->eror ? f_error_order_(l->eror, l) : 1;
	l->t ? f_time_order_(a, l) : 1;
	ft_printf("total %d\n", l->st_block);
	while (i < a[0]->c_arg)
	{
		(a[i]->d_name || a[i]->f_name) ? val = a[i]->m_st.st_mode : 1;
		(a[i]->d_name || a[i]->f_name) ? o_g_p_permissions_(val) : 1;
		(a[i]->d_name || a[i]->f_name) ? f_link_uid_gid_t_(a, l, i) : 1;
		(a[i]->d_name || a[i]->f_name) ? ft_printf("\n") : 1;
		i++;
	}
	return (1);
}
