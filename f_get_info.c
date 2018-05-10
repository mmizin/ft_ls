/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ct_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:40:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/20 17:40:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		f_part_one_(t_get_file ***a, t_ls *l)
{
	if (S_ISLNK((*a)[l->i]->m_st.st_mode))
	{
		stat(l->fname, &(*a)[l->i]->m_st);
		if (S_ISDIR((*a)[l->i]->m_st.st_mode))
			((*a)[l->i]->d_name = f_sdup((*a)[l->i]->f_name)) &&
			((*a)[l->i]->f_name = NULL);
		else
			lstat(l->fname, &(*a)[l->i]->m_st);
	}
	if ((*a)[0]->f_name)
		f_print_(a, l);
	f_get_arg_in_print(a, (*a)[0]->d_name, l);
	return (1);
}

int 			f_get_info(t_get_file ***a, t_ls *l)
{
	if (l->only_ls)
		if (f_part_one_(a, l))
			return (1);
	while (l->i < (*a)[0]->c_arg)
	{
		l->dname = (*a)[l->i]->d_name;
		l->fname = (*a)[l->i]->f_name;
		l->dname ? lstat(l->dname, &(*a)[l->i]->m_st) : 0;
		l->fname ? lstat(l->fname, &(*a)[l->i]->m_st) : 0;
		if (S_ISLNK((*a)[l->i]->m_st.st_mode))
		{
			stat(l->fname, &(*a)[l->i]->m_st);
			if (S_ISDIR((*a)[l->i]->m_st.st_mode))
				((*a)[l->i]->d_name = f_sdup(l->fname)) &&
						((*a)[l->i]->f_name = NULL);
			else
				lstat(l->fname, &(*a)[l->i]->m_st);
		}
		l->st_block += (*a)[l->i]->m_st.st_blocks;
		l->i++;
	}
	return (1);
}
