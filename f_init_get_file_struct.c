/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_get_file_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:48:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/08 19:48:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 		f_ls_init_get_file_stru_(t_get_file ***a, int i)
{
	(*a)[i]->lng_name = 0;
	(*a)[i]->lng_link = 0;
	(*a)[i]->lng_uid = 0;
	(*a)[i]->lng_gid = 0;
	(*a)[i]->lng_maj = 0;
	(*a)[i]->lng_min = 0;
	(*a)[i]->lng_siz_f = 0;
	return (1);
}
