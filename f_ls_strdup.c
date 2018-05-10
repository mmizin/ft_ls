/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ls_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:59:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/20 19:59:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*f_sdup(const char *s1)
{
	char	*stwo;
	size_t	len;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	stwo = (char *)malloc(sizeof(char) * (len + 1));
	if (stwo == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		stwo[len] = s1[len];
		len++;
	}
	stwo[len] = '\0';
	return (stwo);
}
