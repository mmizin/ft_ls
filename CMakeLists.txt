cmake_minimum_required(VERSION 3.9)
project(FT_LS C)

set(CMAKE_C_STANDARD 99)

include_directories(FT_LS nmizin_printf)

AUX_SOURCE_DIRECTORY(nmizin_printf PRINTF)

add_executable(FT_LS
        ${PRINTF}
        main.c
        ft_ls.h
        f_check_argv.c
        f_ls_strcmp.c
        f_initialize_struct.c
        f_reset_variables.c
        f_ls_strdup.c
        f_ls_join_free.c
        f_ls_str_length.c
        f_memmaloc.c
        f_bzero.c
        f_get_files_from_argv.c
        f_print_.c
        f_get_arg_in_print.c
        f_count_files_in_print.c
        f_print_only_ls.c
        f_flag_a_.c
        f_flag_L_.c
        f_link_uid_gid_t_.c
        f_spl.c
        f_order_a_z.c
        f_num_size_.c
        f_init_get_file_struct.c
        f_get_length_param_.c
        f_initialize_flags.c f_error_order_.c f_permis_denied_.c f_o_g_p_permissions_.c f_get_tty_.c)

link_libraries(FT_LS libftprintf.a)