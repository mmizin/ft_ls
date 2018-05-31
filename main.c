/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 22:45:37 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/30 22:45:48 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_ls			lls;
	t_get_file		**args;

	f_initialize_ls(&lls, argc);
	f_ls_chk_ar(argv, &lls);
	args = f_get_file_from_argv(argv, &lls);
	f_print_(args, &lls);
	return (0);
}
