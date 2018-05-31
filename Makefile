# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmizin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 23:27:06 by nmizin            #+#    #+#              #
#    Updated: 2018/05/30 23:27:12 by nmizin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC =	main.c \
		f_ls_chec_argv.c \
		f_get_files_from_argv.c \
		f_count_files_.c \
		f_print_.c \
		f_error_order_.c \
		f_print_ls.c \
		f_flag_l_.c \
		f_get_arg_in_print.c \
		f_initialize_struct.c \
		f_link_uid_gid_t_.c \
		f_spl.c \
		f_order_a_z.c \
		f_num_size_.c \
		f_get_length_param_.c \
		f_chmod_.c \
		f_get_tty_.c \
		f_free_.c \
		f_order_time_.c \
		f_order_a_z_r_.c \
		f_lib_func_.c \
		f_fill_error_.c \

INC = ft_ls.h

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	make -C nmizin_printf
	gcc $(FLAGS) $(OBJ) -I nmizin_printf nmizin_printf/libftprintf.a -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(INC)
	gcc $(FLAGS) -c $< -o $@

clean:
	make -C nmizin_printf/ clean
	rm -rf $(OBJ_DIR)
	find . -name ".*.sw[klmpon]" -o -name "*.o" -exec rm -rf {} \;

fclean: clean
	make -C nmizin_printf/ fclean
	rm -rf $(NAME)

re: fclean all
