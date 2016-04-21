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

char text[TEXT_SIZE] = TEXT_DATA;

void decode_text(kromosom k, char decoded_text[TEXT_SIZE])
{
	int i, j;

	for (i = 0; i < (int)(TEXT_SIZE / 16); i++) {
		for (j = 0; j < 16; j++) {
			decoded_text[i * 16 + j] = text[i * 16 + k[j]];
		}
	}
}
