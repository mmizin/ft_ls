/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:26:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/20 21:26:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

int 	f_print_files(t_ls *lls)
{
	char 		*name;

	int i = 0;
	while (i < lls->c)
	{
//		name = lls->get_name[i]->name;
		printf("name = %s\n", name);
		i++;
	}
	return (1);
}

