/**
 * @file   	bslist.h
 * @author 	BernardT
 *
 * @date	24 mai 2014, 21:33
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

#ifndef BSLIST_H
#    define	BSLIST_H

typedef struct _BSElement {
	void *data;
	struct _BSElement *next;
} bselement;

typedef struct _BSList {
	bselement *first;
	bselement *last;
} bslist;

static inline bselement *new_element(void *data) {
	bselement *elt = (bselement *) calloc(1, sizeof (bselement));
	elt->data = data;
	return elt;
}

static inline bslist *new_list(void) {
	bslist *list = (bslist *) calloc(1, sizeof (bslist));
	return list;
}

static inline bselement *bsl_add_data(bslist *list, void *data) {
	bselement *elt = new_element(data);
	if (list->last != NULL) {
		list->last->next = elt;
	}
	list->last = elt;
	if (list->first == NULL) {
		list->first = elt;
	}
	return elt;
}

static inline bselement *bsl_push_data(bslist *list, void *data) {
	bselement *elt = new_element(data);
	elt->next = list->first;
	list->first = elt;
	if (list->last == NULL) {
		list->last = elt;
	}
	return elt;
}

void bsl_for_each(bslist *list, void (*on_data)(void *data));
#endif	/* BSLIST_H */

