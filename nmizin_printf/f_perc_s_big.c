/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_perc_s_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:22:27 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/15 14:37:10 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_find_weight(const char **format, char c, va_list ap)
{
	int		width;
	int		sign;

	sign = 1;
	while (format && **format != c && **format != '.')
	{
		if (**format == '-')
			sign = -1;
		if (**format == '*')
		{
			width = va_arg(ap, int);
			width = width < 0 ? width : width * sign;
			return (width);
		}
		if (**format >= '1' && **format <= '9')
		{
			width = ft_atoi(*format) * sign;
			while ((**format >= '0' && **format <= '9') || **format == 'l')
				(*format)++;
			return (width);
		}
		(**format != c && **format != '.') && (*format)++;
	}
	return (0);
}

static void	f_find_precision(const char **format, char c, va_list ap, t_var *v)
{
	int		point;
	va_list	first;

	point = 0;
	v->p = 0;
	va_copy(first, ap);
	while (**format && **format != c)
	{
		if (**format == '.')
		{
			point++;
			if (*(*format + 1) == '*')
				v->p = va_arg(ap, int);
			if ((*(*format + 1) >= '0' && *(*format + 1) <= '9'))
				v->p = ft_atoi((*format) + 1);
		}
		(**format != c) && (*format)++;
	}
	if (!point)
		v->p = -1;
}

static int	f_find_bytes(t_var *v, wchar_t *str)
{
	v->l = 0;
	while (str && *str)
	{
		v->i = *str++;
		if (v->i <= 127)
			v->l += 1;
		else if (v->i <= 2027)
			(v->l += 2) && (v->cur_max = 1);
		else if (v->i <= 65535)
			(v->l += 3) && (v->cur_max = 1);
		else
			(v->l += 4) && (v->cur_max = 1);
		if (v->l >= v->p && v->p > 0)
		{
			v->p = v->l;
			break ;
		}
	}
	if (v->p < 0)
		v->p = v->l;
	return (1);
}

int			f_perc_s_big(va_list ap, const char **format, t_var *v)
{
	wchar_t *str;
	wchar_t res;

	res = '\0';
	v->res = v->ts == l ? 's' : 'S';
	v->w = f_find_weight(format, v->res, ap);
	f_find_precision(format, v->res, ap, v);
	str = va_arg(ap, wchar_t *);
	f_find_bytes(v, str);
	if (MB_CUR_MAX != 4 && v->cur_max == 1)
	{
		v->bp = -1;
		(**format != '\0') && (*format)++;
		return (0);
	}
	if (v->w > v->l)
		(v->bp += f_w_e_l(' ', v->w - v->l));
	else if (v->w < 0)
		v->sign = (v->w * -1) > 0 ? (v->w * -1) - v->l : 0;
	f_s_ls_print(v, str, res);
	(**format != '\0') && (*format)++;
	f_reset_init(v);
	return (1);
}
