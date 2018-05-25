/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ls_chec_ar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:20:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/18 13:20:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

static char		**f_fill_arr_error_(char **ar, t_ls *l)
{
	char 	**error;
	int 	i;
	int 	j;
	char 	*s;

	i = 1;
	j = 0;
	l->file_on = 0;
	l->dashs = 0;
	error = (char **)malloc(sizeof(char*) * (l->c + 1));            /* ******** */
	error[l->c] = NULL;
	while (i < l->a_rgc)
	{
		s = ar[i];
		if ((f_scmp(ar[i], ".") && (l->dot = 1))
									|| (f_scmp(ar[i], "..") && (l->d_dot = 1)))
									l->file_on = 1;
		if (ar[i][0] == '-' && !l->dashs && !l->file_on)
			l->flag_on = 1;
		if (ar[i][0] != '-')
		{
			lstat(ar[i], &l->l_st) ? error[j++] = f_sdup(ar[i]) : 0;            /* ******** */
			++l->file_on;
		}
		if (ar[i][0] == '-' && !l->file_on && l->dashs && !f_scmp("--", ar[i]))
		{
			lstat(ar[i], &l->l_st) ? error[j++] = f_sdup(ar[i]) : 0;            /* ******** */
		}
		i++;
	}
	return (error);
}

int				f_ls_chk_ar(char **ar, t_ls *l)
{
	int		i;
	int 	j;

	i = 1;
	while (i < l->a_rgc)
	{
		if ((f_scmp(ar[i], ".") && (l->dot = 1))
									|| (f_scmp(ar[i], "..") && (l->d_dot = 1)))
									l->file_on = 1;
		f_scmp(ar[i], "--") ? ++l->dashs && ++l->file_on : 0;
		if (ar[i][0] == '-' && !l->dashs && !l->file_on)
		{
			j = 1;
			while (ar[i][j])
			{
				if ((l->res = ft_strchr(FLAGS, ar[i][j])))
					f_initialize_flg(l, *l->res) && j++;
				else if (!l->res)
				{
					ft_printf("ls: illegal option -- %c\nusage: ls [-%s] "
									  "[file ...]\n", ar[i][j], FLAGS);
					exit(EXIT_FAILURE);
				}
			}
			l->flag_on = 1;
		}
		if (ar[i][0] != '-')
			!lstat(ar[i], &l->l_st) ? ++l->file_on : ++l->c;
		if (ar[i][0] == '-' && !l->file_on && l->dashs && !f_scmp("--", ar[i]))
			!lstat(ar[i], &l->l_st) ? 0 : ++l->c;
		i++;
	}
	if (l->c)
		l->eror = f_fill_arr_error_(ar, l);
	return (l->file_on = 0);
}


