

#include "ft_ls.h"

int 			main(int argc, char **argv)
{
	t_ls			lls;
	t_get_file		**args;
//	char 			**copy;
	int i;

//	if (!f_scmp(argv[0], "./ft_ls"))
//		return (0);
	i = 0;
//	copy = (char **)malloc(sizeof(char *) * (argc));
//	while (i < argc && argv[i])
//	{
//		copy[i] = f_sdup(argv[i]);
//		i++;
//	}
//	copy[argc] = NULL;
	f_ls_initialize(&lls, argc);
	f_ls_chk_ar(argv, &lls);
	f_reset_variabels(&lls);
	args = f_get_file_from_argv(argv, &lls);
		f_reset_variabels(&lls);
	f_print_(args, &lls);
	return (0);
}