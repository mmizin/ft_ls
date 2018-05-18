/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_permis_denied_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:00:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/17 15:00:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

int 		f_permis_denied_(t_get_file **a, t_ls *l)
{
	int 			i;
	DIR				*dir;

	i = 0;
	if (a[i]->c_arg == 1)
	{
		if (!(dir = opendir(a[i]->d_name)))
		{
			l->eror ? ft_printf("%s:\n", a[i]->d_name) : 0;
			ft_printf("ls: %s: %s\n", a[i]->d_name, strerror(errno));
		}
		else
			return (1);
		exit(EXIT_SUCCESS);
	}

	while (i < a[0]->c_arg)
	{
		if (a[i]->d_name)
		{
			if (!(dir = opendir(a[i]->d_name)))
			{
				ft_printf("%s:\n", a[i]->d_name);
				ft_printf("ls: %s: %s\n", a[i]->d_name, strerror(errno));
			}
		}
		i++;
	}
	return (1);
}
