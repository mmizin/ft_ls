/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handl_s_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:23:43 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/15 16:40:30 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		f_part_one(t_var *v, wchar_t res)
{
	if (v->p >= 4)
	{
		(res = v->i >> 18 | 0xF0) && (v->bp += write(1, &res, 1));
		(res = ((v->i >> 12) & 0x3F) | 0x80) && (v->bp += write(1, &res, 1));
		(res = ((v->i >> 6) & 0x3F) | 0x80) && (v->bp += write(1, &res, 1));
		res = (v->i & 0x3F) | 0x80;
		(v->bp += write(1, &res, 1)) && (v->p -= 4);
	}
}

int				f_s_ls_print(t_var *v, wchar_t *str, wchar_t res)
{
	while (str && *str)
	{
		v->i = *str++;
		if (v->i <= 127 && v->p >= 1)
			(v->bp += write(1, str - 1, 1)) && (v->p -= 1);
		else if (v->i <= 2047 && v->p >= 2)
		{
			(res = v->i >> 6 | 0xc0) && (v->bp += write(1, &res, 1));
			res = (v->i & 0x003F) | 0x80;
			(v->bp += write(1, &res, 1)) && (v->p -= 2);
		}
		else if (v->i <= 65535 && v->p >= 3)
		{
			(res = v->i >> 12 | 0xE0) && (v->bp += write(1, &res, 1));
			(res = (v->i >> 6 & 0x3F) | 0x80) && (v->bp += write(1, &res, 1));
			res = (v->i & 0x3F) | 0x80;
			(v->bp += write(1, &res, 1)) && (v->p -= 3);
		}
		else
			f_part_one(v, res);
	}
	(v->sign) && (v->bp += f_w_e_l(' ', v->sign)) && (v->sign = 0);
	return (1);
}
