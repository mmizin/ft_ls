/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_perc_o_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:34:29 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/11 14:57:58 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		f_find_weight(const char **format, char c, va_list ap, t_var *v)
{
	int	sign;

	sign = 1;
	while (format && **format != c && **format != '.')
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
	int res;
	int check;

	while (**format && **format != c)
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

static int		f_width(uintmax_t v_arg)
{
	int count;

	count = 0;
	if (v_arg == 0)
		count++;
	while (v_arg)
		++count && (v_arg /= 8);
	return (count);
}

int				f_perc_o_o(va_list ap, const char **format, t_var *v)
{
	uintmax_t				v_arg;
	char					*argv;
	char					tmp;

	tmp = v->res;
	(v->ts == l && v->res == 'O') && (tmp = 'o');
	f_sign(format, v);
	v->w = f_find_weight(format, tmp, ap, v);
	v->p = f_find_precision(format, tmp, ap);
	f_spec_the_size_for_x_and_x(&v_arg, v, ap);
	v->l = f_width(v_arg);
	argv = ft_itoa_base(v_arg, 8, v->res);
	f_handl_o_o(v, v_arg, argv);
	while (**format != tmp)
		(*format)++;
	(**format != '\0') && (*format)++;
	free(argv);
	f_reset_init(v);
	return (1);
}
