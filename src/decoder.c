/*
 * In The Name Of God
 * ========================================
 * [] File Name : decoder.c
 *
 * [] Creation Date : 15-03-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#include "defs.h"

#include <string.h>
#include <stdlib.h>

void decode_block(const char block[16], char decoded_block[16], kromosom k)
{
	int i;

	for (i = 0; i < 16; i++)
		decoded_block[i] = block[k[i]];
}

void decode(const char *text, char **decoded_text, kromosom k)
{
	int i;

	*decoded_text = malloc(strlen(text) * sizeof(char));

	for (i = 0; i < strlen(text); i += 16)
		decode_block(text + i, *decoded_text + i, k);
}
