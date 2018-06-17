/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pf_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:29:06 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/16 14:33:32 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		f_len(intmax_t number)
{
	int count;

	count = 0;
	if (number == 0)
		count++;
	while (number)
	{
		count++;
		number /= 10;
	}
	return (count);
}

char			*f_itoa(intmax_t number)
{
	int		len;
	char	*new;

	len = f_len(number);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	new[--len] = number % 10 < 0 ? -1 * (number % 10) + '0' : number % 10 + '0';
	while (number /= 10)
	{
		number = number < 0 ? -number : number;
		new[--len] = number % 10 + '0';
	}
	return (new);
}
