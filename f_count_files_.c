/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_count_files_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 00:09:26 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/31 00:09:32 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	f_part_one_(t_get_variables *v, char **argv, t_ls *l)
{
	if ((f_scmp(argv[v->i], ".") && l->dot)
		|| (f_scmp(argv[v->i], "..") && l->d_dot))
		++v->i && ++v->c;
	else if (argv[v->i][0] == '.')
		++v->i;
	else if ((argv[v->i] && argv[v->i][0]) && !lstat(argv[v->i], &l->l_st))
		++v->c && ++v->i;
	else
		++v->i;
	return (1);
}

int			f_count_file(char **argv, int argc, t_ls *l)
{
	t_get_variables			v;

	f_initialize_var(&v) && (v.i = 1);
	while (v.i < argc)
	{
		if (l->a_b && !l->a)
		{
			if (f_scmp(argv[v.i], ".") || f_scmp(argv[v.i], ".."))
				++v.i;
			else if ((argv[v.i] && argv[v.i][0]) && !lstat(argv[v.i], &l->l_st))
				++v.c;
			++v.i;
		}
		else if (!l->a)
		{
			f_part_one_(&v, argv, l);
		}
		else if (l->a)
		{
			if ((argv[v.i] && argv[v.i][0]) && !lstat(argv[v.i], &l->l_st))
				++v.c;
			++v.i;
		}
	}
	return (v.c);
}

static int f_part_two_(t_ls *l, char *name, int *c)
{
	if (l->a_b && !l->a)
	{
		if (f_scmp(name, ".") || f_scmp(name, ".."))
			;
		else
			(*c)++;
	}
	else if (!l->a)
	{
		if (name[0] == '.')
			;
		else
			(*c)++;
	}
	else
		(*c)++;
	return (1);
}

int			f_count_files_in_print(char *name, t_ls *l)
{
	DIR				*dir;
	int				c;
	int				i;
	struct dirent	*dp;

	c = 0;
	i = 0;
	if (!(dir = opendir(name)))
	{
		f_permis_denied_(name, l);
		return (c);
	}
	while ((dp = readdir(dir)) != NULL)
	{
		f_part_two_(l, dp->d_name, &c);
	}
	closedir(dir);
	return (c);
}
