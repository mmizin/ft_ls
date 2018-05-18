/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_ar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:16:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/18 19:16:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		f_fill_arr_error_(char **argv, t_ls *l)
{
	int i;

	i = 1;
	l->eror = (char **)malloc(sizeof(char *) * (l->c + 1));
	l->eror[l->c] = NULL;
	l->dir_on = 0;
	while (i < l->a_rgc)
	{
		(argv[i][0] != '-' && !stat(argv[i], &l->mystat)) ? l->dir_on = 1 : 0;
		if (argv[i][0] != '-' && stat(argv[i], &l->mystat))
		{
			l->dir_on = 1;
			l->eror[l->j] = (char *)malloc(sizeof(char)
											* ((l->tmp = f_slen(argv[i])) + 1));
			l->eror[l->j][l->tmp] = '\0';
			l->eror[l->j++] = f_sdup(argv[i]);
		}
		f_scmp("-", argv[i]) ? l->dir_on = 1 : 0;
		if (f_scmp(argv[i], "--"))
		{
			l->dir_on ? 0 : (l->dashs = 1);
		}
		if ((f_scmp(argv[i], ".")
			 && (l->dot = 1)) || (f_scmp(argv[i], "..") && (l->d_dot = 1)))
		{
			l->dir_on = 1;
		}
		else if (argv[i][0] == '-' && !l->dashs && !l->dir_on)
			;
		else if (argv[i][0] == '-' && (!l->dashs && l->dir_on))
		{
			if (stat(argv[i], &l->mystat))
			{
				l->eror[l->j] = (char *)malloc(sizeof(char)
									   * ((l->tmp = f_slen(argv[i])) + 1));
				l->eror[l->j][l->tmp] = '\0';
				l->eror[l->j++] = f_sdup(argv[i]);
			}
		}
		else if (argv[i][0] == '-' && l->dashs)
		{
			if (stat(argv[i], &l->mystat))
			{
				l->eror[l->j] = (char *)malloc(sizeof(char)
									   * ((l->tmp = f_slen(argv[i])) + 1));
				l->eror[l->j][l->tmp] = '\0';
				l->eror[l->j++] = f_sdup(argv[i]);
			}
		}
		i++;
	}
	return (1);
}



int				f_ls_chk_argv(char **argv, t_ls *l)
{
	int		i;
	int 	j;

//		if (!f_scmp(ar[0], "./ft_ls"))
//		{
//			ft_printf(":::COMAND LS WAS NOT FOUND:::\n");			/* Change from 1 to 0 */
//			exit(EXIT_FAILURE);
//		}
	i = 1;
	while (i < l->a_rgc)
	{
		(argv[i][0] != '-' && !stat(argv[i], &l->mystat)) ? l->dir_on = 1 : 0;
		(argv[i][0] != '-' && stat(argv[i], &l->mystat)) ? ++l->c && (l->dir_on = 1) : 0;
		f_scmp("-", argv[i]) ? l->dir_on = 1 : 0;
		if (f_scmp(argv[i], "--"))
		{
			l->dir_on ? 0 : (l->dashs = 1);
		}
		if ((f_scmp(argv[i], ".") && (l->dot = 1)) || (f_scmp(argv[i], "..") && (l->d_dot = 1)))
		{
			l->dir_on = 1;
		}
		else if (argv[i][0] == '-' && !l->dashs && !l->dir_on)
		{
			j = 1;
			while (argv[i][j])
			{
				if ((l->res = ft_strchr(FLAGS, argv[i][j])))
				{
					f_initialize_flg(l, *l->res) && j++;
				}

				else if (!l->res)
				{
					ft_printf("ls: illegal option -- %c\nusage: ls [-%s] "
									  "[file ...]\n", argv[i][j], FLAGS);
					exit(EXIT_FAILURE);
				}
			}
		}
		else if (argv[i][0] == '-' && (!l->dashs && l->dir_on))
		{
			!stat(argv[i], &l->mystat) ? 0 : l->c++;
		}
		else if (argv[i][0] == '-' && l->dashs)
		{
			!stat(argv[i], &l->mystat) ? 0 : l->c++;
		}
		i++;
	}
	if (l->c)
		f_fill_arr_error_(argv, l);
	return (l->dir_on = 0);
}

