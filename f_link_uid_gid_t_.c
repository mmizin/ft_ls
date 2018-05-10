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

int 				f_link_uid_gid_t_(t_get_file ***a, t_ls *l, int i)
{
	l->res = NULL;
	l->uid = (*a)[i]->m_st.st_uid;
	l->gid = (*a)[i]->m_st.st_gid;
	l->t2 = (*a)[i]->m_st.st_mtimespec.tv_sec;
	l->res = ctime(&l->t2);
	l->spl = f_spl(l->res);
	l->link = (*a)[i]->m_st.st_nlink;
	l->s_uid = getpwuid(l->uid);
	l->s_gid = getgrgid(l->gid);

	/* NUMBER OF LINK */
	printf("  %*d ",(*a)[0]->lng_link , l->link);

	/* IF FLAG 'n' IS ON PRINT USER ID & GROUP ID */
	l->n ? printf("%-8u%-14u", l->s_uid->pw_uid, l->s_uid->pw_gid)
		 : printf("%-8s %-14s", l->s_uid->pw_name, l->s_gid->gr_name);

	/* SIZE OF FILE */
	if (S_ISCHR((*a)[i]->m_st.st_mode) || S_ISBLK((*a)[i]->m_st.st_mode))
	{
		l->maj = major((*a)[i]->m_st.st_rdev);
		l->min = minor((*a)[i]->m_st.st_rdev);
		if (minor((*a)[i]->m_st.st_rdev) > 255 ||
				minor((*a)[i]->m_st.st_rdev) < 0)
			printf("%8d, 0x%08x", l->maj, l->min);
		else
			printf("%8d, %4d", l->maj, l->min);
	}
	else
		printf(" %lld", (*a)[i]->m_st.st_size);

	/* TIME */
	if ((time(&l->t1) - l->t2) > 15778800)
		printf(" %-8s %-8s %-8s", l->spl[1], l->spl[2], l->spl[4]);
	else if ((l->t2 - time(&l->t1)) > 15778800)
		printf(" %-1s %-1s %-1s", l->spl[1], l->spl[2], l->spl[4]);
	else
		printf(" %-1s %-1s %-1.5s", l->spl[1], l->spl[2], l->spl[3]);

	/* NAME FILE */
	if (S_ISLNK((*a)[i]->m_st.st_mode))
	{
		l->fname = f_jo_fr((*a)[0]->path_name, (*a)[i]->d_name
											   ? (*a)[i]->d_name
											   : (*a)[i]->f_name, 0);
		(readlink(l->fname, l->buf, l->bufsiz)) != -1 ?
		printf(" %s -> %s", (*a)[i]->f_name, l->buf) : 0;
		f_bzero(l->buf, PATH_MAX);
		free(l->fname);
	}
	else printf(" %s", (*a)[i]->d_name ? (*a)[i]->d_name : (*a)[i]->f_name);
	return (1);
}
