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

static int		f_fill_arr_error_(char **argv, int argc, t_ls *l, int i)
{
	int						k;
	struct stat				m_stat;
	int						leter;
	int 					z;

	k = 0;
	z = 1;
	l->eror = (char **)malloc(sizeof(char *) * (i + 1));
	l->eror[i] = NULL;
	while (k < i && argv[z])
	{
		if (argv[z][0] == '-' && (!f_scmp(argv[z - 1], "--")))
			z++;
		if (argv[z] && lstat(argv[z], &m_stat))
		{
			l->eror[l->j] = (char *) malloc(sizeof(char)
											* ((leter = f_slen(argv[z])) + 1));
			l->eror[l->j][leter] = '\0';
			l->eror[l->j++] = f_sdup(argv[z]);
		}
		z++;
		k++;
	}
	return (1);
}

static int 		f_count_file(char **argv, int argc, t_ls *l)
{
	int						k;
	struct stat				m_stat;
	int 					i;
	int						j;

	k = 1;
	i = 0;
	j = 1;
	while (k < argc && argv[j])
	{
		if (argv[j][0] == '-' && (!f_scmp(argv[j - 1], "--")))
			j++;
		if (!lstat(argv[j], &m_stat))
			l->c++;
		else if (argv[j] && argv[j][0])
			i++;
		j++;
		k++;
	}
	f_fill_arr_error_(argv, argc, l, i);
	return (1);
}

int				f_get_file_from_argv(char **argv, t_ls *l, t_get_file **a)
{
	struct stat				m_st;

	l->res = (**argv);
	f_count_file(*argv, l->a_rgc, l);
//	l->c == 0 ? f_get_arg_in_print(a, ".", l) && f_print_only_ls_(a, l) : 1;
	l->c == 0 ? l->c = 1 : 1;
	(*a) = (t_get_file **)malloc(sizeof(t_get_file *) * l->c);
	(*a)[l->i] = (t_get_file *)malloc(sizeof(t_get_file));
	(*a)[l->i]->c_arg = l->c;
	while (l->i < l->c)
	{
		(*argv)++;
		if (f_scmp("./ft_ls", *argv))
			*argv++;
		if (!lstat(l->only_ls ? "." : (**argv), &m_st))
		{
			(S_ISDIR(m_st.st_mode)) ? (*a)[l->i]->d_name = f_sdup(**argv)
									: ((*a)[l->i]->d_name = NULL);
			(S_ISDIR(m_st.st_mode)) ? (l->dir_on = 1) &&
					((*a)[l->i]->f_name = NULL) :
			((*a)[l->i]->f_name = f_sdup(**argv)) && ((*a)[l->i]->d_name = NULL);
			l->st_block += m_st.st_blocks;
			if (++l->i != l->c)
				(*a)[l->i] = (t_get_file *)malloc(sizeof(t_get_file));
		}
	}
	(**argv) = l->res;
	return (1);
}
