/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_initialize_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:52:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/18 19:52:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			f_initialize_ls(t_ls *lls, int argc)
{
	lls->a = 0;
	lls->d = 0;
	lls->f = 0;
	lls->a_b = 0;
	lls->r = 0;
	lls->r_b = 0;
	lls->l = 0;
	lls->n = 0;
	lls->t = 0;
	lls->ls = 0;
	lls->dot = 0;
	lls->d_dot = 0;
	lls->a_rgc = argc;
	lls->bufsiz = PATH_MAX;
	lls->st_block = 0;
	lls->dir_on = 0;
	lls->file_on = 0;
	lls->dash = 0;
	lls->res = NULL;
	return (1);
}

int			f_initialize_flg(t_ls *l, char res)
{
	if (res == 'l')
		l->l = 1;
	else if (res == 'R')
		l->r_b = 1;
	else if (res == 'r')
		l->r = 1;
	else if (res == 't')
		l->t = 1;
	else if (res == 'a')
		l->a = 1;
	else if (res == 'n')
	{
		l->n = 1;
		l->l = 1;
	}
	else if (res == '1')
		l->one = 1;
	else if (res == 'A')
		l->a_b = 1;
	else if (res == 'f')
		++l->f && ++l->a;
	else if (res == 'd')
		++l->d;
	return (1);
}

int			f_initialize_lng(t_get_file **a, int i)
{
	a[i]->lng_name = 0;
	a[i]->lng_link = 0;
	a[i]->lng_uid = 0;
	a[i]->lng_gid = 0;
	a[i]->lng_maj = 0;
	a[i]->lng_min = 0;
	a[i]->lng_siz_f = 0;
	return (1);
}

int			f_initialize_var(t_get_variables *ls)
{
	ls->i = 0;
	ls->j = 0;
	ls->k = 0;
	ls->c = 0;
	ls->tmp = 0;
	ls->ptr1 = NULL;
	ls->ptr2 = NULL;
	return (1);
}
