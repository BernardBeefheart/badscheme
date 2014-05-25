/**
 * @file   	bsfiles-utils.c
 * @author 	BernardT
 *
 * @date	25 mai 2014, 00:30
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

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/unistd.h>

#include "badscheme.h"

// file size, POSIX compliant
// https://www.securecoding.cert.org/confluence/display/seccode/FIO19-C.+Do+not+use+fseek()+and+ftell()+to+compute+the+size+of+a+regular+file
bschar *get_file_content(const char *file_name) {
	off_t file_size;
	bschar *buffer;
	struct stat stbuf;
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1) {
		on_error("Cannot open file for read");
	}

	if ((fstat(fd, &stbuf) != 0) || (!S_ISREG(stbuf.st_mode))) {
		/* Handle error */
		close(fd);
		on_error("Cannot open file for stats");
	}

	file_size = stbuf.st_size;

	if (file_size != 0) {
		buffer = (char*) malloc(file_size + 1);
		if (read(fd, buffer, file_size) != file_size) {
			on_error("Cannot read file");
		}
		*(buffer + file_size) = 0;
	} else {
		buffer = NULL;
	}
	close(fd);
	return buffer;
}