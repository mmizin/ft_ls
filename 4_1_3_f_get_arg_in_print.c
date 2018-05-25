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

static int 			f_part_four_(t_ls *l, t_get_file **tmp, int i)
{
	if (f_scmp(".", tmp[i]->f_name) || f_scmp("..", tmp[i]->f_name))
		;
	else if (S_ISREG(tmp[i]->m_st.st_mode))
		;
	else if (S_ISDIR(tmp[i]->m_st.st_mode))
	{
		free(l->kek);
		l->kek = f_jo_fr(tmp[0]->path_name,
						 tmp[i]->f_name, 0);             /* +++ */
		f_get_arg_in_print(l->kek, l);
		free(l->kek);
		l->kek = NULL;
	}
	return (1);
}

static int			f_part_three_(t_get_file **a, t_ls *l)
{
	t_get_file		**tmp;
	int 			i;

	if (l->r_b)
	{
		tmp = NULL;
		tmp = f_makkok_(a);
		f_print_only_ls_(a, l);
		((l->r && l->t) || (l->t && !l->r)) ? f_time_order_(tmp, l) : 1;
		l->r ? f_order_a_z_r(tmp, l) : 0;
		!l->t && !l->r ? f_order_a_z_(tmp, l) : 0;
		i = 0;
		while (i < tmp[0]->c_arg)
		{
			f_part_four_(l, tmp, i);
			i++;
		}
		f_free_for_r_b_(tmp);
		free(tmp);
	}
	return (1);
}

static int			f_part_two_(t_get_file **a, t_ls *l, struct dirent *dp, int *i)
{
	a[*i] = (t_get_file *)malloc(sizeof(t_get_file));
	f_ls_init_get_file_stru_(a, *i);
	a[*i]->c_arg = l->c;
	*i == 0 ? a[0]->path_name = f_sdup(l->kek) : (a[*i]->path_name = NULL);							 /* +++ */
	free(l->kek);
	l->kek = f_jo_fr(a[0]->path_name, dp->d_name, 0);						 /* +++ */
	lstat(l->kek, &a[*i]->m_st);
	if (S_ISLNK(a[*i]->m_st.st_mode))
	{
		stat(l->kek, &a[*i]->m_st);
		a[*i]->f_name = f_sdup(dp->d_name);				 /* +++ */
	}
	else
		a[*i]->f_name = f_sdup(dp->d_name);				 /* +++ */
	l->st_block += a[*i]->m_st.st_blocks;
	f_get_param_lng_(a, l, *i, dp);
	(*i)++;
	return (1);
}

static int 			f_part_one_(t_get_file ***a, t_ls *l, char *name)
{
	int	count;

	count = f_slen(name);
	name[count - 1] == '/' ? l->kek = f_sdup(name)
						   : (l->kek = f_jo_fr(name, "/", 0));		/* +++ */
	l->c = f_count_files_in_print(l->kek, l);
	*a = (t_get_file **)malloc(sizeof(t_get_file *) * l->c);		 /* +++ */
	l->st_block = 0;
	return (1);
}

t_get_file 			**f_get_arg_in_print(char *name, t_ls *l)
{
	struct dirent	*dp;
	t_get_file		**a;
	DIR				*dir;
	int 			i;

	i = 0;
	a = NULL;
	f_part_one_(&a, l, name);

	if (!l->c)
		return NULL;
	if (!(dir = opendir(name)))
		if (f_permis_denied_(name, l))
			return NULL;

	while ((dp = readdir(dir)) != NULL)
	{
		if (!l->a && (dp->d_name[0] == '.' && (!l->dot || !l->d_dot)))
				;
		else
			f_part_two_(a, l, dp, &i);
	}

	f_part_three_(a, l);
	if (!l->r_b)
		free(l->kek);
	f_reset_variabels(l);
	closedir(dir);
	return (a);
}
