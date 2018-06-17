/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_wright_exact_length.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 20:31:28 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/15 15:11:26 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_w_e_l(char c, int length)
{
	int		i;
	char	buff[length];

	if (length <= 0)
		return (0);
	i = length;
	while (length)
		buff[--length] = c;
	buff[i] = '\0';
	write(1, &buff, i);
	return (i);
}
