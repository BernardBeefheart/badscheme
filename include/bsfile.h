/**
 * @file   	bsfile.h
 * @author 	BernardT
 *
 * @date	23 mai 2014, 23:11
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

#ifndef BSFILE_H
#    define	BSFILE_H

typedef struct {
	bschar *name;
	bschar *content;
} bsfile;

static inline bsfile *new_file(char *file_name) {
	bsfile *f = (bsfile *)calloc(1, sizeof(bsfile));
	// @TODO : c'est pas beau du tout!
	f->name = file_name;
	return f;
}

void load_file(bsfile *file);

static inline void vload_file(void *vfile) {
	bsfile *file = (bsfile *)vfile;
	load_file(file);
}
#endif	/* BSFILE_H */

