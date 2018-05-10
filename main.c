#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <assert.h>
#include <locale.h>

#include "ft_ls.h"
#include "nmizin_printf/ft_printf.h"

static int 		f_if_only_ls_(char **argv, t_ls *l)
{
	if (l->a_rgc == 2 || l->a_rgc == 3)			/* WARNING	change to 1 and 2  WARNING */
	{
			l->only_ls = 1;
	}
	return (1);
}

int 			main(int argc, char **argv)
{
	t_ls			lls;
	t_get_file		**args;

	f_ls_initialize(&lls, argc);
		f_if_only_ls_(argv, &lls);

	f_ls_chk_argv(argv, &lls);
		f_reset_variabels(&lls);

	f_get_file_from_argv(argv, &lls, args);
		f_reset_variabels(&lls);

	f_get_info(&args, &lls);
		f_reset_variabels(&lls);

	f_print_(&args, &lls);

	/* ------------------------------ RECURSIOM ----------------------------- */


	/* --------------------------------------------------------------------------------------------------------------------------------------------------------- */

//
//	DIR *dir
//	struct dirent *dp;
//	struct stat **p_arrs;
//	int t_argc;
//	struct stat mystat;
//	int count;
//	mode_t val;
//
//	count = 0;
//	dir = opendir(".");
////	t_argc = argc;
//// 						/* LIST ARGUMENTS *ARGV */
////	while (--t_argc)											/* LIST ARGUMENTS *ARGV */
////	{															/* LIST ARGUMENTS *ARGV */
////		argv++;													/* LIST ARGUMENTS *ARGV */
////		printf("ARGV ::: %s\n", *argv);							/* LIST ARGUMENTS *ARGV */
////	}
//	while ((dp = readdir(dir)) != NULL)
//	{
//		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
//		{
//			// do nothing (straight logic)
//		}
//		else
//		{
////			printf("FILE_NAME ::: %s\n", dp->d_name);
//			stat(dp->d_name, &mystat);
//			count++;
////			val = (mystat.st_mode & ~S_IFMT);
////			(S_ISDIR(mystat.st_mode)) ? printf("INFO ::: THIS FILE <%s> \tIS DIRECTORY\n",
////											   dp->d_name) : printf(
////					"INFO ::: THIS FILE <%s> \tIS NOT DIRECTORY\n", dp->d_name);
//			printf("BLOCK ::: %lld\n", mystat.st_blocks);
//		}
//
////	printf("ST_S ::: %hu\n", p_arrs[0]->st_mode);
////	if (S_ISDIR(p_arrs[2]->st_mode))
////	{
////		printf("::: IT IS DIR ::::\n");
////		p_arrs[2] = S_IFDIR;
//	}
//
////	p_arrs = f_crt_p_arrs(count);
////	if (p_arrs[2] == S_IFDIR)
////		printf("::: YES IT WORKING :::\n");
////	closedir(dir);
////		return (0);

/* --------------------------------------------------------------------------------------------------------------------------------------------------------- */

//	struct stat sb;
//
//
//	if (stat(argv[1], &sb) == -1) {
//		perror("stat");
//		exit(EXIT_SUCCESS);
//	}
//
//	printf("File type:                ");
//
//	switch (sb.st_mode & S_IFMT) {
//		case S_IFBLK:  printf("block device\n");            break;
//		case S_IFCHR:  printf("character device\n");        break;
//		case S_IFDIR:  printf("directory\n");               break;
//		case S_IFIFO:  printf("FIFO/pipe\n");               break;
//		case S_IFLNK:  printf("symlink\n");                 break;
//		case S_IFREG:  printf("regular file\n");            break;
//		case S_IFSOCK: printf("socket\n");                  break;
//		default:       printf("unknown?\n");                break;
//	}
//
//	printf("I-node number:            %ld\n", (long) sb.st_ino);
//
//	printf("Mode:                     %lo (octal)\n", (unsigned long) sb.st_mode);
//
//	printf("Link count:               %ld\n", (long) sb.st_nlink);
//	printf("Ownership:                UID=%ld   GID=%ld\n",
//		   (long) sb.st_uid, (long) sb.st_gid);
//
//	printf("Preferred I/O block size: %ld bytes\n",
//		   (long) sb.st_blksize);
//	printf("File size:                %lld bytes\n",
//		   (long long) sb.st_size);
//	printf("Blocks allocated:         %lld\n",
//		   (long long) sb.st_blocks);
//
//	printf("Last status change:       %s", ctime(&sb.st_ctime));
//	printf("Last file access:         %s", ctime(&sb.st_atime));
//	printf("Last file modification:   %s", ctime(&sb.st_mtime));
//
//	exit(EXIT_SUCCESS);

/* --------------------------------------------------------------------------------------------------------------------------------------------------------- */

//	DIR *mydir;
//	struct dirent *myfile;
//	struct stat mystat;
//
//	mydir = opendir(argv[1]);
//	char buf[512];
//	while((myfile = readdir(mydir)) != NULL)
//	{
//		struct tm *time_stamp=localtime(&mystat.st_mtime);
//		sprintf(buf, "%s/%s", argv[1], myfile->d_name);
//		stat(buf, &mystat);
//		stat(myfile->d_name, &mystat);
//		mode_t val;
//
//		val=(mystat.st_mode);
//		(val & S_IRUSR) ? printf("r") : printf("-");			/* OWNER HAS READ PERMISSION      */
//		(val & S_IFDIR) ? printf("d") : printf("-");			/* OWNER HAS READ PERMISSION      */
//		(val & S_IWUSR) ? printf("w") : printf("-");			/* OWNER HAS WRITE PERMISSION     */
//		(val & S_IXUSR) ? printf("x") : printf("-");			/* OWNER HAS EXECUTE PERMISSION   */
//		(val & S_IRGRP) ? printf("r") : printf("-");			/* GROUP HAS READ PERMISSION      */
//		(val & S_IWGRP) ? printf("w") : printf("-");			/* GROUP HAS WRITE PERMISSION     */
//		(val & S_IXGRP) ? printf("x") : printf("-");			/* GROUP HAS EXECUTE PERMISSION   */
//		(val & S_IROTH) ? printf("r") : printf("-");			/* OTHERS HAVE READ PERMISSION    */
//		(val & S_IWOTH) ? printf("w") : printf("-");			/* OTHERS HAVE WRITE PERMISSION   */
//		(val & S_IXOTH) ? printf("x") : printf("-");			/* OTHERS HAVE EXECUTE PERMISSION */
//		printf("\t%d",mystat.st_nlink);
//		printf("\t%d",mystat.st_uid);
//		printf("\t%d",mystat.st_gid);
//		printf("\t%lld",mystat.st_size);
//		char buffer[80];
//		strftime(buffer,10,"%b",time_stamp);
//
//		printf("\t%4d %s %2d ", time_stamp->tm_year+1900,buffer,time_stamp->tm_mday);
//		printf(" %s\n", myfile->d_name);
//	}
//	closedir(mydir);

/* --------------------------------------------------------------------------------------------------------------------------------------------------------- */
//	struct dirent  *dp;
//	struct stat     statbuf;
//	struct passwd  *pwd;
//	struct group   *grp;
//	struct tm      *tm;
//	char            datestring[256];
//	DIR 			*dir;
//
//	dir = opendir(".");
///* Loop through directory entries. */
//	while ((dp = readdir(dir)) != NULL) {
//
//
//		/* Get entry's information. */
//		if (stat(dp->d_name, &statbuf) == -1)
//			continue;
//
//
//		/* Print out type, permissions, and number of links. */
////		printf("%10.10s", statbuf.st_mode);
//		printf("%4d", statbuf.st_nlink);
//
//
//		/* Print out owner's name if it is found using getpwuid(). */
//		if ((pwd = getpwuid(statbuf.st_uid)) != NULL)
//			printf(" %-8.8s", pwd->pw_name);
//		else
//			printf(" %-8d", statbuf.st_uid);
//
//
//		/* Print out group name if it is found using getgrgid(). */
//		if ((grp = getgrgid(statbuf.st_gid)) != NULL)
//			printf(" %-8.8s", grp->gr_name);
//		else
//			printf(" %-8d", statbuf.st_gid);
//
//
//		/* Print size of file. */
//		printf(" %9jd", (intmax_t)statbuf.st_size);
//
//
//		tm = localtime(&statbuf.st_mtime);
//
//
//		/* Get localized date string. */
//		strftime(datestring, sizeof(datestring), nl_langinfo(D_T_FMT), tm);
//
//
//		printf(" %s %s\n", datestring, dp->d_name);
//	}

/* --------------------------------------------------------------------------------------------------------------------------------------------------------- */
	return (0);
}