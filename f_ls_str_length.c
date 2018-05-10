/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ls_str_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:55:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/21 19:55:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		f_slen(const char *s)
{
	unsigned char	*string;
	int				len;

	string = (unsigned char *)s;
	len = 0;
	while (string && *string)
	{
		len++;
		string++;
	}
	return (len);
}