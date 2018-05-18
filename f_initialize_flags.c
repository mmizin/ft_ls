/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_initialize_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:41:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/16 19:41:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

int 		f_initialize_flg(t_ls *l, char res)
{
	if (res == 'l')
		l->l = 1;
	else if (res == 'R')
		l->r_b = 1;
	else if (res == 'r')
		l->r = 1;
	else if (res == 't')
		l->t = 1;
	else if (res == 'a')
		l->a = 1;
	else if (res == 'n')
		l->n = 1;
	return (1);
}

