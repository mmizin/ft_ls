/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:16:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/18 19:16:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

static int 		f_initialize_flg(t_ls *lls, char res)
{
	if (res == 'l')
		lls->l = 1;
	else if (res == 'R')
		lls->r_b = 1;
	else if (res == 'r')
		lls->r = 1;
	else if (res == 't')
		lls->t = 1;
	else if (res == 'a')
		lls->a = 1;
	else if (res == 'n')
		lls->n = 1;
	return (1);
}

static int		f_part_one_(char **argv, t_ls *v, t_ls *lls)
{
	if ((f_scmp(".", argv[v->i]) && (lls->dot = 1)) ||
			(f_scmp("..", argv[v->i]) && (lls->dot = 1)))
	{
		return (0);
	}
	else if ((argv[v->i][0] == '-' && argv[v->i][1] == '-') || lls->dashs)
	{
		lls->dashs = 1;
		return (0);
	}
	return (1);
}

static int 		f_get_flag(t_ls *lls, t_ls *v, char **argv)
{
	if (lls->dot && lls->on_flag)		/* проверяем что если есть ('.' || '..' || '-') && один из флагов уже включен */
	{
		ft_printf(":::ERROR ::: AFTER DOT WAS FOUND FLAGS:::\n");
		return (0);
	}

	if ((v->res = (ft_strchr(FLAGS, argv[v->i][v->j]))))
		f_initialize_flg(lls, *(v->res));
	if (v->res == NULL)
	{
		ft_printf("ls: illegal option -- %c\n", argv[v->i][v->j]);
		ft_printf("usage: ls [%s] [file ...]\n", FLAGS);
		exit(EXIT_FAILURE);
	}
	if (argv[v->i][v->j] && argv[v->i][v->j + 1] == '-')
	{
		ft_printf("ls: illegal option -- -\n");
		ft_printf("usage: ls [%s] [file ...]\n", FLAGS);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int				f_ls_chk_argv(char **argv, t_ls *lls)
{
	t_ls	v;

	f_ls_initialize(&v, lls->a_rgc);
		if (!f_scmp(argv[1], "./ft_ls"))
		{
			ft_printf(":::COMAND LS WAS NOT FOUND:::\n");			/*Change from 1 to 0 */
			exit(EXIT_FAILURE);
		}
		while (++v.i < lls->a_rgc)
		{
			v.j = 0;
			while (argv[v.i][v.j])
			{
				v.j++;
				if (!f_part_one_(argv, &v, lls))
					break ;
				if ((argv[v.i][0] == '-' && argv[v.i][1] != '-') && (!lls->dashs))
				{
					lls->on_flag = 1;
					if (!f_get_flag(lls, &v, argv))
						break ;
				}
				else
					break ;
			}
		}
	return (1);
}
