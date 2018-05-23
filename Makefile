
NAME = ft_ls

SRC =	1_main.c \
		2_f_ls_chec_argv.c \
        3_0_f_get_files_from_argv.c \
        3_1_f_count_file_in_argv_.c \
        4_0_f_print_.c \
        4_1_1_f_error_order_.c \
        4_1_2_0_f_print_only_ls.c \
        4_1_2_1_f_flag_L_.c \
        4_1_3_f_get_arg_in_print.c \
        f_ls_strcmp.c \
        f_initialize_struct.c \
        f_reset_variables.c \
        f_ls_strdup.c \
        f_ls_join_free.c \
        f_ls_str_length.c \
        f_bzero.c \
        f_count_files_in_print.c \
        f_link_uid_gid_t_.c \
        f_spl.c \
        f_order_a_z.c \
        f_num_size_.c \
        f_init_get_file_struct.c \
        f_get_length_param_.c \
        f_initialize_flags.c \
        f_permis_denied_.c \
        f_o_g_p_permissions_.c \
        f_get_tty_.c \
        f_free_.c \
        f_time_order_.c \
        f_order_a_z_r_.c \
        f_memdel.c \

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
