/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_initialize_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:52:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/18 19:52:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		f_ls_initialize(t_ls *lls, int argc)
{
	lls->a				= 0;
	lls->r				= 0;
	lls->r_b			= 0;
	lls->l				= 0;
	lls->n				= 0;
	lls->t				= 0;
	lls->ls				= 0;
	lls->dot			= 0;
	lls->d_dot			= 0;
	lls->i				= 0;
	lls->a_rgc			= argc;
	lls->j				= 0;
	lls->c				= 0;
	lls->tmp			= 0;
	lls->bufsiz			= PATH_MAX;
	lls->st_block		= 0;
	lls->dir_on			= 0;
	lls->file_on		= 0;
	lls->dashs			= 0;
	lls->only_ls		= 0;
	lls->res			= NULL;
	lls->fname			= NULL;
	return (1);
}
