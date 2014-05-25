/**
 * @file   	interp.c
 * @author 	BernardT
 *
 * @date	23 mai 2014, 22:59
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

#include "badscheme.h"

typedef enum {
	bsst_none,
	bsst_open_list,
	bsst_close_list,
	bsst_space,
	bsst_new_line,
	bsst_lexem,

} bsinterp_state;

typedef enum {
	bstyp_unknown,
	bstyp_number,
	bstyp_string,
	bstyp_variable,
} bsinterp_type;

typedef struct {
	bsinterp_type type;
	char *str;
} bsobject;
static bslist *programm = NULL;

void interp_string(char *str) {
	bsinterp_state state = bsst_none;
	bsinterp_state new_state;
	char c;
	ENTER_FUNC();
	if (programm == NULL) {
		programm = new_list();
	}
	while ((c = *(str++)) != 0) {
		switch (c) {
			case '(':
				new_state = bsst_open_list;
				break;
			case ')':
				new_state = bsst_close_list;
				break;
			case ' ':
			case '\t':
				new_state = bsst_space;
				break;
			case '\n':
				new_state = bsst_new_line;
				break;
			case '0' ... '9':
			case 'A' ... 'Z':
			case 'a' ... 'z':
			case '-':
			case '_':
			case '+':
			case '*':
			case '.':
			case '/':
				new_state = bsst_lexem;
				break;
			default:
				new_state = bsst_none;
				break;
		}
	}
	if (state != new_state) {

	}
	LEAVE_FUNC();
}