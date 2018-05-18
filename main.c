

#include "ft_ls.h"

int 			main(int argc, char **argv)
{
	t_ls			lls;
	t_get_file		**args;

	args = NULL;
	f_ls_initialize(&lls, argc);

	f_ls_chk_argv(argv, &lls);
		f_reset_variabels(&lls);
	args = f_get_file_from_argv(argv, &lls, args);
		f_reset_variabels(&lls);
	f_print_(args, &lls);

}