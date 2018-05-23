/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_f_count_file_in argv_.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:50:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/18 16:50:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

int 		f_count_file(char **argv, int argc, t_ls *l)
{
	struct stat				l_stat;
	int 					i;

	i = 1;
	while (i < argc)
	{
		if (!l->a && (!l->dot || !l->d_dot))
		{
			if (argv[i][0] == '.' && (!l->dot || !l->d_dot))
			{
				i++;
				++l->c;
			}

			else
			{
				if ((argv[i] && argv[i][0]) && !lstat(argv[i], &l_stat))
					l->c++;
				i++;
			}
		}
		else
		{
			if ((argv[i] && argv[i][0]) && !lstat(argv[i], &l_stat))
				l->c++;
			i++;
		}
	}
	return (1);
}