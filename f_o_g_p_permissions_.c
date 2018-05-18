/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_o_g_p_permissions_.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:07:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/17 21:07:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void		o_g_p_permissions_(mode_t val)
{
	S_ISLNK(val) ? ft_printf("l") : 1 && S_ISREG(val) ? ft_printf("-") : 1;
	S_ISDIR(val) ? ft_printf("d") : 1 && S_ISCHR(val) ? ft_printf("c") : 1;
	S_ISBLK(val) ? ft_printf("b") : 1 && S_ISFIFO(val) ? ft_printf("p") : 1;
	S_ISSOCK(val) ? ft_printf("s") : 1;
	(val & S_IRUSR) ? ft_printf("r") : ft_printf("-");
	(val & S_IWUSR) ? ft_printf("w") : ft_printf("-");
	if ((val & S_ISUID) && !(val & S_IXUSR))
		ft_printf("S");
	else
		((val & S_ISUID) && (val & S_IXUSR))
		? ft_printf("s") : (val & S_IXUSR) ? ft_printf("x") : ft_printf("-");
	(val & S_IRGRP) ? ft_printf("r") : ft_printf("-");
	(val & S_IWGRP) ? ft_printf("w") : ft_printf("-");
	if ((val & S_ISGID) && !(val & S_IXGRP))
		ft_printf("S");
	else
		((val & S_ISGID) && (val & S_IXGRP))
		? ft_printf("s") : (val & S_IXGRP) ? ft_printf("x") : ft_printf("-");
	(val & S_IROTH) ? ft_printf("r") : ft_printf("-");
	(val & S_IWOTH) ? ft_printf("w") : ft_printf("-");
	if (val & S_ISVTX && !(val & S_IXOTH))
		ft_printf("T");
	else
		(val & S_ISVTX) ? ft_printf("t") : (val & S_IXOTH)
										   ? ft_printf("x") : ft_printf("-");
}
