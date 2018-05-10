/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reset_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:29:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/19 16:29:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		f_reset_variabels(t_ls *lls)
{
	lls->res		= NULL;
	lls->i			= 0;
	lls->j			= 0;
	lls->tmp		= 0;
	lls->dname		= NULL;
	lls->fname		= NULL;
	return (1);
}
