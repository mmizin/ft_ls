/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flag_a_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:37:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/01 19:37:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			f_flag_a_(t_get_file **a, t_ls *l)
{
	int		i;

	i = 0;
	while (i < a[0]->c_arg)
	{
		if ((a[i]->d_name && *a[i]->d_name == '.') || (a[i]->f_name && *a[i]->f_name == '.'))
		{
			l->st_block -= a[i]->m_st.st_blocks;
			a[i]->d_name ? a[i]->d_name = NULL : (a[i]->f_name = NULL);
		}
			i++;
	}
	return (1);
}
