/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_only_ls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 10:04:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/29 10:04:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int 		f_part_two_(t_get_file **a, int *i, t_ls *l)
{
	l->c = 0;
	while (l->c < l->width)
	{
		if (!l->c)
		{
			ft_printf("%-*s", a[0]->lng_name + 8, a[*i]->f_name);
			free(a[*i]->f_name);
			a[*i]->f_name = NULL;
		}
		else if (l->tmp + l->line < a[0]->c_arg && (l->tmp += l->line))
		{
			ft_printf("%-*s", a[0]->lng_name + 8, a[l->tmp]->f_name);
			free(a[*i]->f_name);
			a[*i]->f_name = NULL;
		}
		l->c++;
	}
	ft_printf("\n") && ++l->j && ++*i;
	l->tmp = *i;
	return (1);
}

static int 		f_part_one_(t_get_file **a, t_ls *l)
{
	int i;

	i = 0;
	l->j = 0;
	((l->r && l->t) || (l->t && !l->r)) ? f_time_order_(a, l) : 1;
	l->r && !l->t ? f_order_a_z_r(a, l) : 0;
	!l->t && !l->r ? f_order_a_z_(a, l) : 0;
	f_get_tty_width(a, l);
	l->tmp = i;
	while (i < a[0]->c_arg && l->j < l->line)
		f_part_two_(a, &i, l);
	if (l->ls && !l->r_b)
	{
		f_free_(a);
		free(a);
		exit(EXIT_SUCCESS);
	}
	ft_printf("\n");
	f_free_(a);
	free(a);
	return (1);
}

int 			f_print_only_ls_(t_get_file **a, t_ls *l)
{
	int i;

	i = f_slen(a[0]->path_name);
	if ((f_scmp("./", a[0]->path_name) && (!l->dot || !l->d_dot))
		|| (f_scmp("../", a[0]->path_name) && (!l->dot || !l->d_dot)))
		;
	else if (!l->only_ls || (a[0]->c_arg == 1 && l->dir_on) || l->r_b)
	{
		a[0]->path_name[i - 1] == '/'
		? ft_printf("%.*s:\n", i - 1, a[0]->path_name)
		: ft_printf("%s:\n", a[0]->path_name);
	}
	if (l->l)
		f_flag_l_small_(a, l);
	else
		f_part_one_(a, l);
	if (!l->only_ls || l->r_b)
		return (1);
	exit(EXIT_SUCCESS);
}
