/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:43:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/18 18:43:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		f_free_(t_get_file **a)
{
	int i;
	int tmp;

	if (!a)
		return (1);
	i = 0;
	tmp = a[0]->c_arg;
	while (i < tmp)
	{
		if (a[i]->f_name != NULL)
		{
			free(a[i]->f_name);
			a[i]->f_name = NULL;
			if (a[i]->path_name != NULL)
			{
				free(a[i]->path_name);
				a[i]->path_name = NULL;
			}
			free(a[i]);
		}
		i++;
	}
	free(a);
	return (1);
}
