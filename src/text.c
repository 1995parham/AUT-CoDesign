/*
 * In The Name Of God
 * ========================================
 * [] File Name : text.c
 *
 * [] Creation Date : 10-04-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#include "defs.h"
#include "text.h"

size_t text_length = TEXT_SIZE - 1;
char text[TEXT_SIZE];

void decode_text(const kromosom *k, char decoded_text[text_length + 1])
{
	int i, j;

	for (i = 0; i < (int) (text_length / 16); i++) {
		for (j = 0; j < 16; j++) {
			decoded_text[i * 16 + j] = text[i * 16 + k->d[j] - 1];
		}
	}
}
