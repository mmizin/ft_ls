/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_files_from_argv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:11:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/26 10:11:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int 		f_get_leng_of_argv_(t_get_file **a, t_ls *l)
{
	int i;
	uintmax_t j;
	uintmax_t k;

	i = 0;
	j = 0;
	k = 0;
	while (i < a[0]->c_arg)
	{
		i = f_slen(a[i]->d_name ? a[i]->d_name : a[i]->f_name);
		a[0]->lng_name = a[0]->lng_name < i ? i : a[0]->lng_name;
	}
	return (1);
}

static int 		f_count_file(char **argv, int argc, t_ls *l)
{
	struct stat				m_stat;
	int 					i;

	i = 1;
	if (f_scmp("./ft_ls", argv[i]))																/* DELL THIS  */ /* DELL THIS  */ /* DELL THIS  */
		i++;
	if (f_scmp("/Users/nmizin/CLionProjects/FT_LS/cmake-build-debug/FT_LS", argv[i]))			/* DELL THIS  */ /* DELL THIS  */ /* DELL THIS  */
		i++;
	while (i < argc)
	{
		if ((argv[i] && argv[i][0]) && !lstat(argv[i], &m_stat))
			l->c++;
		i++;
	}
	return (1);
}

t_get_file		**f_get_file_from_argv(char **argv, t_ls *l, t_get_file **a)
{
//	struct stat				m_st;

	l->res = (*argv);
	f_count_file(argv, l->a_rgc, l);
	l->c == 0 ? l->only_ls = 1 : 1;
	if (l->c == 0 && l->eror)
	{
		++l->ls && (l->c = 0);
	}
	else if (l->c == 0 && !l->eror)
	{
		l->c = 1;
	}
	a = (t_get_file **)malloc(sizeof(t_get_file *) * l->c);
	a[l->i] = (t_get_file *)malloc(sizeof(t_get_file));
	a[l->i]->c_arg = l->c;
	while (l->i < l->c)
	{
		argv++;
		if (f_scmp("./ft_ls", *argv))			/* DELL THIS  */
			argv++;
		if (!lstat(l->only_ls ? "." : (*argv), &a[l->i]->m_st))
		{
			if (S_ISLNK(a[l->i]->m_st.st_mode))
			{
				stat(l->only_ls ? "." : (*argv), &a[l->i]->m_st);
				(S_ISDIR(a[l->i]->m_st.st_mode))
				? a[l->i]->d_name = f_sdup(l->only_ls ? "." : *argv)
				: (a[l->i]->d_name = NULL);
				(S_ISDIR(a[l->i]->m_st.st_mode))
				? (l->dir_on = 1) && (a[l->i]->f_name = NULL)
				: (a[l->i]->f_name = f_sdup(l->only_ls ? "." : *argv))
				  && (a[l->i]->d_name = NULL);
			}
			else
			{
				(S_ISDIR(a[l->i]->m_st.st_mode))
				? a[l->i]->d_name = f_sdup(l->only_ls ? "." : *argv)
				: (a[l->i]->d_name = NULL);
				(S_ISDIR(a[l->i]->m_st.st_mode))
				? (l->dir_on = 1) && (a[l->i]->f_name = NULL)
				: (a[l->i]->f_name = f_sdup(l->only_ls ? "." : *argv))
				  && (a[l->i]->d_name = NULL);
			}
			if (++l->i != l->c)
				a[l->i] = (t_get_file *)malloc(sizeof(t_get_file));
		}
	}
	*argv = l->res;
	return (a);
}
