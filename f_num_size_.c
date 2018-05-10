/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_num_size_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:35:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/08 14:35:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		f_num_size(uintmax_t num, int base)
{
	int count;

	count = 0;
	if (num == 0)
		count++;
	while (num)
	{
		count++;
		num /= base;
	}
	return (count);
}
