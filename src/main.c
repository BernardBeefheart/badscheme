/**
 * @file   	main.c
 * author 	BernardT
 *
 * @date 	21 mai 2014, 21:29
 *
 *
 * Copyright (c) 2014 Bernard TATIN (bernard . tatin @ outlook.fr)
 *
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *	* Redistributions of source code must retain the above copyright notice,
 * 		this list of conditions and the following disclaimer.
 *	* Redistributions in binary form must reproduce the above copyright notice,
 * 		this list of conditions and the following disclaimer in the documentation
 * 		and/or other materials provided with the distribution.
 *	* Neither the name of the copyright holder nor the names of its contributors
 * 		may be used to endorse or promote products derived from this software
 * 		without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "badscheme.h"

static void banner(void) {
    fprintf(stdout, ";; %s %s\n", progname, version);
}

_Noreturn static void dohelp(const int exit_code) {
	fprintf(stdout, "%s [--help] file1 file2 ...\n", progname);
	exit(exit_code);
}

/*
 *
 */
int main(int argc, char** argv) {
	int i;
	bslist *files = new_list();

    banner();
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

