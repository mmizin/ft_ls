/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memmaloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:31:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/24 11:31:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*f_memalloc(size_t size)
{
	char *arr;

	arr = (char *)malloc(sizeof(char) * size);
	if (!arr)
		return (NULL);
	f_bzero(arr, size);
	return (arr);
}