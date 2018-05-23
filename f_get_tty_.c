/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_tty_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:10:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/17 21:10:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

int		f_get_tty_width(t_get_file **a, t_ls *l)
{
	struct ttysize wnd;

	ioctl(0, TIOCGSIZE, &wnd);
//	printf("::: LINE ::: %d\n", wnd.ts_cols);
//	printf("::: LNG_NAME ::: %ju\n", a[0]->lng_name);
	l->width = wnd.ts_cols / (a[0]->lng_name + 8) + 1;
//	l->width = 4;																/* DELL THIS DELL THIS DELL THIS */
	l->line = (a[0]->c_arg / l->width) > 0 ? (a[0]->c_arg / l->width) + 1 : 1;
	return (1);
}