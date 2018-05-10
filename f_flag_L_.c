/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flag_L_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:42:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/02 19:42:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		o_g_p_permissions_(mode_t val)
{
	S_ISLNK(val) ? printf("l") : 1 && S_ISREG(val) ? printf("-") : 1;
	S_ISDIR(val) ? printf("d") : 1 && S_ISCHR(val) ? printf("c") : 1;
	S_ISBLK(val) ? printf("b") : 1 && S_ISFIFO(val) ? printf("p") : 1;
	S_ISSOCK(val) ? printf("s") : 1;
	(val & S_IRUSR) ? printf("r") : printf("-");
	(val & S_IWUSR) ? printf("w") : printf("-");
	if ((val & S_ISUID) && !(val & S_IXUSR))
		printf("S");
	else
		((val & S_ISUID) && (val & S_IXUSR))
		? printf("s") : (val & S_IXUSR) ? printf("x") : printf("-");
	(val & S_IRGRP) ? printf("r") : printf("-");
	(val & S_IWGRP) ? printf("w") : printf("-");
	if ((val & S_ISGID) && !(val & S_IXGRP))
		printf("S");
	else
		((val & S_ISGID) && (val & S_IXGRP))
		? printf("s") : (val & S_IXGRP) ? printf("x") : printf("-");
	(val & S_IROTH) ? printf("r") : printf("-");
	(val & S_IWOTH) ? printf("w") : printf("-");
	if (val & S_ISVTX && !(val & S_IXOTH))
		printf("T");
	else
		(val & S_ISVTX) ? printf("t") : (val & S_IXOTH)
										? printf("x") : printf("-");
}

int				f_flag_l_small_(t_get_file ***a, t_ls *l)
{
	int			i;
	mode_t		val;
	char 		*dn;
	char 		*fn;
//	int f;
	i = 0;
	l->r ? f_order_a_z_r(a, l) : f_order_a_z_(a, l);
	l->t ? f_time_order_(a, l) : 1;
	printf("total %d\n", l->st_block);
	while (i < (*a)[0]->c_arg)
	{
//		dn = (*a)[i]->d_name;
//		fn = (*a)[i]->f_name;
//		if (dn || fn)
//			f = (*a)[i]->m_st.st_blksize;
		((*a)[i]->d_name || (*a)[i]->f_name) ? val = (*a)[i]->m_st.st_mode : 1;
		((*a)[i]->d_name || (*a)[i]->f_name) ? o_g_p_permissions_(val) : 1;
		((*a)[i]->d_name || (*a)[i]->f_name) ? f_link_uid_gid_t_(a, l, i) : 1;
		((*a)[i]->d_name || (*a)[i]->f_name) ? printf("\n") : 1;
		i++;
	}
	return (1);
}
