/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_arg_in_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 21:58:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/27 21:58:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_get_file 		**f_get_arg_in_print(t_get_file **a, char *name, t_ls *l)
{
	DIR				*dir;
	struct dirent	*dp;
	int				i;
	int 			c_f;
	char			*kek;

	i = f_slen(name);
	kek = name;
	name[i - 1] == '/' ? 0 : (name = f_jo_fr(name, "/", 0));
	c_f = f_count_files_in_print(name);
	a = (t_get_file **)malloc(sizeof(t_get_file *) * c_f);
	dir = opendir(name);
	i = 0;
	l->st_block = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		a[i] = (t_get_file *)malloc(sizeof(t_get_file));
		i == 0 ? f_ls_init_get_file_stru_(a, i) : 0;
		a[i]->c_arg = c_f;
		a[i]->path_name = f_sdup(name);
		kek = f_jo_fr(name, dp->d_name, 0);
		lstat(kek, &a[i]->m_st);
		if (S_ISLNK(a[i]->m_st.st_mode))
		{
			stat(dp->d_name, &a[i]->m_st);
			if (S_ISDIR(a[i]->m_st.st_mode))
				(a[i]->d_name = f_sdup(dp->d_name)) && (a[i]->f_name = NULL);
			else
				a[i]->f_name = f_sdup(dp->d_name);
		}
		else
		{
			(S_ISDIR(a[i]->m_st.st_mode)) ?
			(a[i]->d_name = f_sdup(dp->d_name)) && (a[i]->f_name = NULL) :
			(a[i]->f_name = f_sdup(dp->d_name)) && (a[i]->d_name = NULL);
		}
		l->st_block += a[i]->m_st.st_blocks;
		f_get_param_lng_(a, l, i, dp);
		i++;
	}
	if (l->r_b)
	{
		ft_printf("\n");
		f_print_only_ls_(a, l);
		i = 0;
		while (i < a[0]->c_arg)
		{
			if (a[i]->f_name)
				;
			else if (a[i]->d_name && !f_scmp(".", a[i]->d_name)
									  && !f_scmp("..", a[i]->d_name))
			{
				kek = f_jo_fr(name, a[i]->d_name, 0);
				f_get_arg_in_print(l->t_arr, kek, l);

			}
			i++;
		}
	}
//	free(kek);
	return (a);
}
