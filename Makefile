
NAME = ft_ls

SRC =	f_bzero.c \
		f_check_argv.c \
		f_count_files_in_print.c \
		f_flag_a_.c \
		f_flag_L_.c \
		f_get_arg_in_print.c \
		f_get_files_from_argv.c \
		f_get_length_param_.c \
		f_init_get_file_struct.c \
		f_initialize_flags.c \
		f_initialize_struct.c \
		f_link_uid_gid_t_.c \
		f_ls_join_free.c \
		f_ls_str_length.c \
		f_ls_strcmp.c \
		f_ls_strdup.c \
		f_memmaloc.c \
		f_num_size_.c \
		f_order_a_z.c \
		f_print_.c \
		f_print_only_ls.c \
		f_reset_variables.c \
		f_spl.c \
		main.c \
		f_permis_denied_.c \
		f_error_order_.c \
		f_o_g_p_permissions_.c \

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
