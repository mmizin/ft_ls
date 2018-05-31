/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_f_ls_chec_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 22:48:29 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/30 22:48:35 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		f_part_three_(t_get_variables *v, t_ls *l, char **ar)
{
	if (ar[v->i][0] != '-')
		lstat(ar[v->i], &l->l_st) ? ++v->c && ++l->file_on && ++v->tmp
									: ++l->file_on && ++v->tmp;
	if (ar[v->i][0] == '-')
	{
		if (v->tmp)
			lstat(ar[v->i], &l->l_st) ? ++v->c && ++v->tmp : ++v->tmp;
		else if (!l->dash)
			++v->c && ++v->tmp;
	}
}

static void		f_part_one_(t_get_variables *v, t_ls *l, char **ar)
{
	if ((f_scmp(ar[v->i], ".") && ++l->dot && ++v->tmp)
		|| (f_scmp(ar[v->i], "..") && ++l->d_dot && ++v->tmp))
		l->file_on = 1;
	if (f_scmp(ar[v->i], "--"))
	{
		l->file_on ? ++v->c && ++v->tmp : ++l->dash && ++l->file_on && ++v->tmp;
		return ;
	}
	if (ar[v->i][0] == '-' && !l->dash && !l->file_on)
	{
		v->j = 1;
		while (ar[v->i][v->j])
		{
			if ((l->res = ft_strchr(FLAGS, ar[v->i][v->j])))
				f_initialize_flg(l, *l->res) && v->j++;
			else if (!l->res)
			{
				ft_printf("ft_ls: illegal option -- %c\nusage: ls [-%s] "
					"[file ...]\n", ar[v->i][v->j], FLAGS);
				exit(EXIT_FAILURE);
			}
		}
		return ;
	}
	f_part_three_(v, l, ar);
}

int				f_ls_chk_ar(char **ar, t_ls *l)
{
	t_get_variables	v;

	f_initialize_var(&v);
	v.i = 1;
	while (v.i < l->a_rgc)
	{
		f_part_one_(&v, l, ar);
		v.i++;
	}
	if (v.c)
		l->eror = f_fill_arr_error_(ar, l, v);
	l->d ? l->r_b = 0 : 0;
	return (1);
}
