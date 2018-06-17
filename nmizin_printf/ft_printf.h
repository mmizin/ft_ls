/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:09:06 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/16 15:08:34 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVERSIONS "sSpdDioOuUxXcC"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <locale.h>
# include <wchar.h>
# include "limits.h"
# include <stdint.h>
# include <sys/types.h>

typedef enum			e_size_specificators
{
	hh, h, l, ll, j, z
}						t_ts;

typedef struct			s_main
{
	int					bp;
	int					p;
	long long int		w;
	int					l;
	int					c;
	int					cur_max;
	int					sign;
	wint_t				i;
	char				res;
	const char			*begin;
	t_ts				ts;
	int					pl;
	int					min;
	int					hes;
	int					spa;
	int					zer;
	long long int		tmp;
}						t_var;

int						ft_printf(const char *format, ...);
void					f_chk(va_list ap, const char *format, t_var *v);
int						f_no_perc_at_all(const char **format, t_var *v);
void					f_chk_let_conv
							(const char **format, va_list ap, t_var *v);
int						f_perc_s_small
							(va_list ap, const char **format, t_var *v);
int						f_perc_s_big(va_list ap, const char **format, t_var *v);
int						f_w_e_l(char c, int length);
int						ft_atoi(const char *str);
int						ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
int						f_from_per_to_per
							(va_list ap, const char **format, t_var *v);
int						f_perc_c_small
							(va_list ap, const char **format, t_var *v);
int						f_perc_c_big(va_list ap, const char **format, t_var *v);
int						f_perc_d_small
							(va_list ap, const char **format, t_var *v);
int						f_sign(const char **format, t_var *v);
char					*f_itoa(intmax_t number);
void					f_for_d_and_i_flags
							(t_var *v, intmax_t v_arg, char *argv);
int						f_spec_the_size_for_d_and_i
							(intmax_t *v_arg, t_var *v, va_list ap);
int						f_perc_x_x(va_list ap, const char **format, t_var *v);
int						f_reset_init(t_var *v);
int						f_spec_the_size_for_x_and_x
							(uintmax_t *v_arg, t_var *v, va_list ap);
char					*ft_itoa_base
							(uintmax_t value, int base, char res);
void					f_handl_x_x(t_var *v,
							unsigned long long int v_arg, char *argv);
int						f_perc_o_o
							(va_list ap, const char **format, t_var *v);
void					f_handl_o_o(t_var *v,
							uintmax_t v_arg, char *argv);
int						f_perc_p_small
							(va_list ap, const char **format, t_var *v);
int						f_s_ls_print(t_var *v, wchar_t *str, wchar_t res);

#endif
