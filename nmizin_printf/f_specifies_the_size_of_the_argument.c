/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_specifies_the_size_of_the_argument.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:22:27 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/16 15:39:38 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_spec_the_size_for_d_and_i(intmax_t *v_arg, t_var *v, va_list ap)
{
	if (v->ts == l || v->res == 'D')
		(*v_arg) = va_arg(ap, long);
	else if (v->ts == hh)
	{
		(*v_arg) = va_arg(ap, int);
		(*v_arg) = (signed char)(*v_arg);
	}
	else if (v->ts == h)
	{
		(*v_arg) = va_arg(ap, int);
		(*v_arg) = (short)(*v_arg);
	}
	else if (v->ts == ll)
		(*v_arg) = va_arg(ap, long long);
	else if (v->ts == j)
		(*v_arg) = va_arg(ap, intmax_t);
	else if (v->ts == z)
		(*v_arg) = va_arg(ap, ssize_t);
	else
		(*v_arg) = va_arg(ap, int);
	return (1);
}

int	f_spec_the_size_for_x_and_x(uintmax_t *v_arg, t_var *v, va_list ap)
{
	if (v->ts == hh)
	{
		(*v_arg) = va_arg(ap, unsigned int);
		(*v_arg) = (unsigned char)(*v_arg);
	}
	else if (v->ts == h)
	{
		(*v_arg) = va_arg(ap, unsigned int);
		(*v_arg) = (unsigned short)(*v_arg);
	}
	else if (v->ts == l || v->res == 'O' || v->res == 'U')
		(*v_arg) = va_arg(ap, unsigned long);
	else if (v->ts == ll)
		(*v_arg) = va_arg(ap, unsigned long long);
	else if (v->ts == j)
		(*v_arg) = va_arg(ap, uintmax_t);
	else if (v->ts == z)
		(*v_arg) = va_arg(ap, size_t);
	else
		(*v_arg) = va_arg(ap, unsigned int);
	return (1);
}
