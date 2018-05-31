/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fill_error_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:54:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/29 18:54:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		f_part_two_(t_get_variables *var, t_ls *l, char **ar,
								char **error)
{
	if (ar[var->i][0] != '-')
		lstat(ar[var->i], &l->l_st)
		? (error[var->j++] = f_sdup(ar[var->i])) && ++l->file_on && ++var->tmp
		: ++l->file_on && ++var->tmp;
	if (ar[var->i][0] == '-')
	{
		if (var->tmp)
			lstat(ar[var->i], &l->l_st)
			? (error[var->j++] = f_sdup(ar[var->i])) && ++var->tmp : ++var->tmp;
		else if (!l->dash)
		{
			++var->tmp;
			error[var->j++] = f_sdup(ar[var->i]);
		}
	}
}

static void		f_part_one_(char **ar, t_ls *l, t_get_variables *var,
													char **error)
{
	if ((f_scmp(ar[var->i], ".") && ++l->dot && ++var->tmp)
		|| (f_scmp(ar[var->i], "..") && ++l->d_dot && ++var->tmp))
		l->file_on = 1;
	if (f_scmp(ar[var->i], "--"))
	{
		l->file_on ?
		(error[var->j++] = f_sdup(ar[var->i])) && ++var->tmp
					: ++l->dash && ++l->file_on && ++var->tmp;
		return ;
	}
	if (ar[var->i][0] == '-' && !l->dash && !l->file_on)
		return ;
	f_part_two_(var, l, ar, error);
}

char			**f_fill_arr_error_(char **ar, t_ls *l, t_get_variables v)
{
	char				**error;
	t_get_variables		var;

	var.i = 1;
	var.j = 0;
	l->file_on = 0;
	l->dash = 0;
	error = (char **)malloc(sizeof(char*) * (v.c + 1));
	error[v.c] = NULL;
	while (var.i < l->a_rgc)
	{
		f_part_one_(ar, l, &var, error);
		var.i++;
	}
	return (error);
}
