/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_count_files_in_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 22:23:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/27 22:23:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 			f_count_files_in_print(char *name)
{
	DIR				*dir;
	int 			c;
	struct dirent	*dp;

	c = 0;
	dir = opendir(name);
	while ((dp = readdir(dir)) != NULL)
		c++;
	return (c);
}