/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_perc_p_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:22:27 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/15 14:10:28 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_perc_p_small(va_list ap, const char **format, t_var *v)
{
	void	*x;
	char	*res;
	int		i;

	x = va_arg(ap, void *);
	res = ft_itoa_base((unsigned long long)x, 16, v->res);
	i = ft_strlen(res);
	v->bp += write(1, "0x", 2);
	v->bp += write(1, res, i);
	while (**format != v->res)
		(*format)++;
	(**format != '\0') && (*format)++;
	free(res);
	f_reset_init(v);
	return (1);
}
