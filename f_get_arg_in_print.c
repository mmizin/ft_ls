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

static int			f_part_three_(t_get_file **a, t_ls *l, t_get_variables *v)
{
	t_get_file		**tmp;

	f_print_ls_(a, l);
	!l->f && l->t ? f_time_order_(a, l) : 1;
	!l->f && l->r && !l->t ? f_order_a_z_r(a) : 0;
	!l->f && !l->t && !l->r ? f_order_a_z_(a) : 0;
	!l->f && l->t && l->r ? f_reverse_time_(a) : 0;
	v->i = 0;
	while (v->i < a[0]->c_arg)
	{
		if (f_scmp(".", a[v->i]->f_name) || f_scmp("..", a[v->i]->f_name))
			;
		else if (S_ISREG(a[v->i]->m_st.st_mode))
			;
		else if (S_ISDIR(a[v->i]->m_st.st_mode))
		{
			free(v->ptr2);
			v->ptr2 = f_jo_fr(v->ptr1, a[v->i]->f_name, 0);
			tmp = f_get_arg_in_print(v->ptr2, l);
			f_free_(tmp);
		}
		v->i++;
	}
	return (1);
}

static int			f_part_two_(t_get_file **a, t_ls *l, struct dirent *dp,
								  t_get_variables *v)
{
	int	i;

	i = v->i;
	a[i] = (t_get_file *)malloc(sizeof(t_get_file));
	f_initialize_lng(a, i);
	a[i]->c_arg = v->c;
	i == 0 ? a[i]->path_name = f_sdup(v->ptr2)
		   : (a[i]->path_name = f_sdup(a[0]->path_name));
	free(v->ptr2);
	v->ptr2 = NULL;
	v->ptr2 = f_jo_fr(v->ptr1, dp->d_name, 0);
	lstat(v->ptr2, &a[i]->m_st);
	a[i]->f_name = f_sdup(dp->d_name);
	l->st_block += a[i]->m_st.st_blocks;
	f_get_param_lng_(a, l, i, dp);
	(v->i)++;
	return (1);
}

static int			f_part_one_(t_get_file ***a, t_ls *l, t_get_variables *v,
								  char *name)
{
	int	lng_name;

	v->ptr2 = f_sdup(name);
	lng_name = f_slen(v->ptr2);
	v->ptr2[lng_name - 1] == '/' ? v->ptr1 = f_sdup(v->ptr2)
								 : (v->ptr1 = f_jo_fr(v->ptr2, "/", 0));
	v->c = f_count_files_in_print(v->ptr1, l);
	if (!v->c)
	{
		free(v->ptr1);
		v->ptr1 = NULL;
		free(v->ptr2);
		v->ptr2 = NULL;
		return (v->c);
	}
	*a = (t_get_file **)malloc(sizeof(t_get_file *) * v->c);
	l->st_block = 0;
	return (v->c);
}

static int			f_part_four_(t_get_file **a, t_ls *l, t_get_variables *v,
								   struct dirent *dp)
{
	if (l->a_b && !l->a)
	{
		if (f_scmp(dp->d_name, ".") || f_scmp(dp->d_name, ".."))
			;
		else
			f_part_two_(a, l, dp, v);
	}
	else if (!l->a)
	{
		if (dp->d_name[0] == '.')
			;
		else
			f_part_two_(a, l, dp, v);
	}
	else
		f_part_two_(a, l, dp, v);
	return (1);
}

t_get_file			**f_get_arg_in_print(char *name, t_ls *l)
{
	struct dirent	*dp;
	t_get_file		**a;
	DIR				*dir;
	t_get_variables	v;

	f_initialize_var(&v);
	a = NULL;
	if (!f_part_one_(&a, l, &v, name))
		return (NULL);
	if (!(dir = opendir(name)))
		if (f_permis_denied_(name, l))
			return (NULL);
	while ((dp = readdir(dir)) != NULL)
	{
		f_part_four_(a, l, &v, dp);
	}
	l->r_b ? f_part_three_(a, l, &v) : 0;
	free(v.ptr1);
	free(v.ptr2);
	closedir(dir);
	return (a);
}
