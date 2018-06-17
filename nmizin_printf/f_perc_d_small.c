/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_perc_d_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:22:27 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/16 14:36:01 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		f_find_weight(const char **format, char c, va_list ap, t_var *v)
{
	int		sign;

	sign = 1;
	while (format && **format != c && **format != '.' && **format != 'D')
	{
		if (**format == '-' && (sign = -1))
			;
		if (**format == '*')
		{
			v->w = va_arg(ap, int);
			v->w = v->w < 0 ? v->w : v->w * sign;
			return (v->w);
		}
		if (**format >= '1' && **format <= '9')
		{
			v->w = ft_atoi(*format) * sign;
			while ((**format >= '0' && **format <= '9'))
				(*format)++;
			return (v->w);
		}
		(**format != c && **format != '.') && (*format)++;
	}
	return (0);
}

static int		f_find_precision(const char **format, char c, va_list ap)
{
	int		res;
	int		check;

	while (**format && **format != c && **format != 'D')
	{
		if (**format == '.')
		{
			check = 1;
			if (*(*format + 1) == '*')
				return (va_arg(ap, int));
			if (*(*format + 1) >= '0' && *(*format + 1) <= '9')
			{
				res = ft_atoi(++(*format));
				while (**format >= '0' && **format <= '9')
					(*format)++;
				return (res);
			}
		}
		(*format)++;
	}
	if (check == 1)
		return (0);
	else
		return (-1);
}

static int		f_width(intmax_t v_arg)
{
	int count;

	count = 0;
	if (v_arg == 0)
		count++;
	while (v_arg)
		++count && (v_arg /= 10);
	return (count);
}

int				f_perc_d_small(va_list ap, const char **format, t_var *v)
{
	intmax_t		v_arg;
	char			*argv;
	char			tmp;

	tmp = v->res;
	(v->ts == l && v->res == 'D') && (tmp = 'd');
	f_sign(format, v);
	v->w = f_find_weight(format, tmp, ap, v);
	v->p = f_find_precision(format, tmp, ap);
	f_spec_the_size_for_d_and_i(&v_arg, v, ap);
	v->l = f_width(v_arg);
	argv = f_itoa(v_arg);
	f_for_d_and_i_flags(v, v_arg, argv);
	free(argv);
	while (**format != tmp && **format != 'D')
		(*format)++;
	(**format != '\0') && (*format)++;
	return (1);
}
