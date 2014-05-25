/**
 * @file   	main.c
 * author 	BernardT
 *
 * @date 	21 mai 2014, 21:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "badscheme.h"

static void dohelp(const int exit_code) {
	fprintf(stdout, "badscheme [--help] file1 file2 ...\n");
	exit(exit_code);
}

/*
 *
 */
int main(int argc, char** argv) {
	int i;
	bslist *files = new_list();


	if (argc == 1) {
		dohelp(EXIT_SUCCESS);
	} else {
		for (i = 1; i < argc; i++) {
			if (strcmp(argv[i], "--help") == 0) {
				dohelp(EXIT_SUCCESS);
			} else {
				fprintf(stdout, "new_file(%s)\n", argv[i]);
				bsfile *f = new_file(argv[i]);
				bsl_add_data(files, f);
			}
		}
	}
	init_programm();
	bsl_for_each(files, vload_file);
	return (EXIT_SUCCESS);
}

