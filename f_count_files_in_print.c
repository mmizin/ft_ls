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

int 			f_count_files_in_print(char *name, t_ls *l)
{
	DIR				*dir;
	int 			c;
	struct dirent	*dp;

	c = 0;
	if (!(dir = opendir(name)))
	{
		f_permis_denied_(name, l);
		return (c);
	}
	while ((dp = readdir(dir)) != NULL)
	{
		if (!l->a)
		{
			if (dp->d_name[0] == '.' && (!l->dot || !l->d_dot))
				;
			else
				c++;
		}
		else
			c++;
	}
	return (c);
}