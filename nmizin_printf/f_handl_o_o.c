/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handl_o_O.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:55:48 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/15 12:41:38 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_handl_prec_null(t_var *v, uintmax_t v_arg)
{
	if (!v->p && !v_arg && !v->hes)
	{
		if (!v->pl)
		{
			if (v->w < 0 && (v->w = -v->w))
				;
			v->bp += f_w_e_l(' ', v->w = ((v->spa) && v->w == 0) ? 1 : v->w);
		}
		if (v->pl)
		{
			if (v->w >= 0)
				(v->bp += f_w_e_l(' ', --v->w)) && (v->bp += write(1, "+", 1));
			else if (v->w < 0)
			{
				v->w = v->w * -1 > 1 ? (v->w * -1) - 1 : 1;
				(v->bp += write(1, "+", 1)) && (v->bp += f_w_e_l(' ', v->w));
			}
		}
		return (1);
	}
	return (0);
}

static int	f_part_two(t_var *v, char *argv)
{
	if (v->w >= 0)
	{
		if (v->zer)
		{
			if (*argv != '0')
				v->bp += write(1, "0", !v->hes ? 0 : 1);
			v->bp += f_w_e_l('0', v->w);
		}
		else
			v->bp += f_w_e_l(' ', v->w);
	}
	if (v->w < 0)
	{
		if ((v->min) && (v->min = 0))
			;
		v->w = (v->w * -1) > v->l ?
			(v->w * -1) - v->spa - v->l - v->pl - v->min - v->p - v->hes : 0;
	}
	if (*argv != '0' && !v->zer)
		v->bp += write(1, "0", !v->hes ? 0 : 1);
	v->bp += f_w_e_l('0', v->p);
	v->bp += write(1, argv, v->l);
	if (v->tmp < 0)
		v->bp += f_w_e_l(' ', v->w);
	return (1);
}

static int	f_part_one(t_var *v, char *argv)
{
	v->tmp = v->w;
	if (!v->zer)
		v->p = v->p <= v->l ? 0 : v->p - v->l - v->hes;
	else if (v->zer)
		v->p = (v->p - v->l - v->spa - v->min - v->pl) < 0 ? 0
			: v->p - v->l - v->spa - v->min - v->pl;
	if (v->w >= 0)
		v->w = v->w > v->l ?
			v->w - v->l - v->spa - v->pl - v->min - v->hes - v->p : 0;
	f_part_two(v, argv);
	return (1);
}

void		f_handl_o_o(t_var *v, uintmax_t v_arg, char *argv)
{
	if (v->hes)
		v->hes = 1;
	if (f_handl_prec_null(v, v_arg))
		return ;
	if (f_part_one(v, argv))
		return ;
}
