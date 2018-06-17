NAME = libftprintf.a
INCLUDES = libft.h
CC = gcc -Wall -Wextra -Werror
SRCS = f_check_letter_conversation.c \
		f_check.c \
		f_from_perc_to_perc.c \
		f_handelling_for_d_and_i_flags.c \
		f_pf_itoa.c \
		f_no_perc_at_all.c \
		f_perc_c_big.c \
		f_perc_c_small.c \
		f_perc_d_small.c \
		f_perc_s_big.c \
		f_percent_s_small.c \
		f_sign.c \
		f_specifies_the_size_of_the_argument.c \
		f_wright_exact_length.c \
		f_pf_atoi.c \
		ft_printf.c \
		f_pf_strchr.c \
		f_pf_strlen.c \
		f_perc_x_x.c \
		f_reset_init.c \
		f_from_perc_to_perc.c \
		f_handl_o_o.c \
		f_handl_x_x.c \
		f_perc_p_small.c \
		f_perc_o_o.c \
		f_pf_itoa_base.c \
		f_handl_s_big.c

all: $(NAME)

%.o:%$(SRCS)
	$(CC) -I $(INCLUDES) -c $^

$(NAME): *.o
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@/bin/rm -rf *.o *.out

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

