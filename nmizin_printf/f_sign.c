/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:22:27 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/15 15:09:40 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	f_sign(const char **format, t_var *v)
{
	int go;

	go = 0;
	v->begin = *format;
	v->c = -1;
	while (*(v->begin) && *(v->begin) != v->res)
	{
		(*(v->begin) == '%') && (go = 1);
		(go) && v->c++;
		if (*(v->begin) >= '1' && *(v->begin) <= '9')
			break ;
		if (*(v->begin) == ' ' && (v->spa = 1))
			;
		else if (*(v->begin) == '+' && (v->pl = 1))
			;
		else if (*(v->begin) == '-' && (v->min = 1))
			;
		else if ((*(v->begin) == '0'
			&& (v->c >= 1 && v->c <= 2)) && (v->zer = 1))
			;
		else if (*(v->begin) == '#' && (v->hes = 2))
			;
		v->begin++;
	}
	return (1 && (v->c = 0));
}
