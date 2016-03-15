/*
 * In The Name Of God
 * ========================================
 * [] File Name : decoder.h
 *
 * [] Creation Date : 15-03-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef DECODER_H
#define DECODER_H

#include "defs.h"

void decode_block(const char block[16], char decoded_block[16], kromosom k);

void decode(const char *text, char **decoded_text, kromosom k);

#endif
