/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_order_a_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:20:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/07 13:20:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int		f_lcomp(char *one, char *two, t_ls *l)
{
	if ((!one || !two) || (!*one || !*two))
		return (0);
	while (*one && *two)
	{
		if (*one < *two)
			return (1);
		if (*one > *two)
			return (2);
		one++;
		two++;
	}
	if (*two)
		if (l->r)
			return (1);
	return (0);
}

int 			f_order_a_z_r(t_get_file ***a, t_ls *l)
{
	int				i;
	char			*one;
	char 			*two;
	t_get_file		*arr;

	i = 0;
	while (i < (*a)[0]->c_arg)
	{
		one = (*a)[i]->d_name ? (*a)[i]->d_name : (*a)[i]->f_name;
		if (i + 1 != (*a)[0]->c_arg)
			two = (*a)[i + 1]->d_name ? (*a)[i + 1]->d_name
									  : (*a)[i + 1]->f_name;
		if ((f_lcomp(one, two, l)) == 2)
			i++;
		else if ((f_lcomp(one, two, l)) == 1)
		{
			arr = (*a)[i];
			(*a)[i] = (*a)[i + 1];
			(*a)[i + 1] = arr;
			i = 0;
		}
		else
			i++;
	}
	return (1);
}

int 			f_order_a_z_(t_get_file ***a, t_ls *l)
{
	int				i;
	char			*one;
	char 			*two;
	t_get_file		*arr;

	i = 0;
	while (i < (*a)[0]->c_arg)
	{
		one = (*a)[i]->d_name ? (*a)[i]->d_name : (*a)[i]->f_name;
		if (i + 1 != (*a)[0]->c_arg)
			two = (*a)[i + 1]->d_name ? (*a)[i + 1]->d_name
									  : (*a)[i + 1]->f_name;
		else
			two = NULL;
		if ((f_lcomp(one, two, l)) == 1)
			i++;
		else if ((f_lcomp(one, two, l)) == 2)
		{
			arr = (*a)[i];
			(*a)[i] = (*a)[i + 1];
			(*a)[i + 1] = arr;
			i = 0;
		}
		else
			i++;
	}
	return (1);
}

int 			f_error_order_(char **b)
{
	char	*tmp;
	int		i;
	int 	k;

	i = 0;
	k = 0;
	while (b[i])
		i++;
	while (k < i)
	{
		if ((f_lcomp(b[k], b[k + 1], NULL)) == 2)
		{
			tmp = b[k];
			b[k] = b[k + 1];
			b[k + 1] = tmp;
			k = 0;
		}
		else
			k++;
	}
	k = 0;
	while (k < i)
		printf("ls: %s: No such file or directory\n", b[k++]);
	return (1);
}

int				f_time_order_(t_get_file ***a, t_ls *l)
{
	int i;
	t_get_file *arr;

	i = 0;
	while (i < (*a)[0]->c_arg)
	{
		while ((*a)[i]->f_name == NULL && (*a)[i]->d_name == NULL)
			i++;
		l->t1 = (*a)[i]->m_st.st_mtimespec.tv_sec;
		if (i + 1 == (*a)[0]->c_arg)
			break ;
		else
			l->t2 = (*a)[i + 1]->m_st.st_mtimespec.tv_sec;
		if (l->r && (l->t2 < l->t1))
		{
				arr = (*a)[i];
				(*a)[i] = (*a)[i + 1];
				(*a)[i + 1] = arr;
				i = 0;
		}
		else if (!l->r && l->t2 > l->t1)
		{
			arr = (*a)[i];
			(*a)[i] = (*a)[i + 1];
			(*a)[i + 1] = arr;
			i = 0;
		}
		i++;
	}
	return (1);
}