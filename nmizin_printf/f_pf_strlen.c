/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pf_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:47:18 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/15 17:19:18 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strlen(const char *s)
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
