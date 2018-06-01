/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_name_UID.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:07:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/03 14:07:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			f_part_three_(t_get_file **a, t_ls *l, int i)
{
	t_get_variables v;

	if ((time(&l->t1) - l->t2) > 15778800)
		ft_printf(" %-4s%-3s%s", l->spl[1], l->spl[2], l->spl[4]);
	else if ((l->t2 - time(&l->t1)) > 15778800)
		ft_printf(" %-4s%-3s%-1s", l->spl[1], l->spl[2], l->spl[4]);
	else
		ft_printf(" %-4s%-3s%-1.5s", l->spl[1], l->spl[2], l->spl[3]);
	if (S_ISLNK(a[i]->m_st.st_mode))
	{
		v.ptr2 = f_jo_fr(a[0]->path_name, "/", 0);
		v.ptr1 = f_jo_fr(v.ptr2, a[i]->f_name, 1);
		(readlink(!v.ptr1 ? a[i]->f_name : v.ptr1, l->buf, l->bufsiz)) != -1 ?
		ft_printf(" %s -> %s", a[i]->f_name, l->buf) : 0;
		f_bzero(l->buf, PATH_MAX);
		free(v.ptr1);
	}
	else
	{
		ft_printf(" %s", a[i]->f_name);
	}
	return (1);
}

static int			f_part_two_(t_get_file **a, t_ls *l, int i)
{
	ft_printf("  %*d ", a[0]->lng_link, l->link);
	l->n ? ft_printf("%-*u  %-*u", a[0]->lng_uid,
		l->s_uid->pw_uid, a[0]->lng_gid, l->s_uid->pw_gid)
	: ft_printf("%-*s  %-*s", a[0]->lng_uid,
					l->s_uid->pw_name, a[0]->lng_gid, l->s_gid->gr_name);
	if (S_ISCHR(a[i]->m_st.st_mode) || S_ISBLK(a[i]->m_st.st_mode))
	{
		l->maj = major(a[i]->m_st.st_rdev);
		l->min = minor(a[i]->m_st.st_rdev);
		if (minor(a[i]->m_st.st_rdev) > 255 ||
			minor(a[i]->m_st.st_rdev) < 0)
			ft_printf("%-*d, 0x%0x", a[0]->lng_maj, l->maj, l->min);
		else
			ft_printf(" %*d, %d", a[0]->lng_maj, l->maj, l->min);
	}
	else
		ft_printf("  %*lld", (int)a[0]->lng_siz_f, a[i]->m_st.st_size);
	return (1);
}

static int			f_part_one_(t_get_file **a, t_ls *l, int i)
{
	l->res = NULL;
	l->uid = a[i]->m_st.st_uid;
	l->gid = a[i]->m_st.st_gid;
	l->t2 = a[i]->m_st.st_mtimespec.tv_sec;
	l->res = ctime(&l->t2);
	l->spl = f_spl(l->res);
	l->link = a[i]->m_st.st_nlink;
	l->s_uid = getpwuid(l->uid);
	l->s_gid = getgrgid(l->gid);
	return (1);
}

int					f_link_uid_gid_t_(t_get_file **a, t_ls *l, int i)
{
	char	**tmp;

	f_part_one_(a, l, i);
	tmp = l->spl;
	f_part_two_(a, l, i);
	f_part_three_(a, l, i);
	while (*l->spl && **l->spl)
	{
		free(*l->spl);
		l->spl++;
	}
	free(tmp);
	l->spl = NULL;
	ft_printf("\n");
	return (1);
}
