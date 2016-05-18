/*
 * In The Name Of God
 * ========================================
 * [] File Name : defs.h
 *
 * [] Creation Date : 06-03-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef DEFS_H
#define DEFS_H

#include <stdint.h>
#include <stddef.h>

#include "lfsr.h"

#define TEXT_SIZE 8193

typedef struct {
	/* Kromosom key */
	uint8_t d[16];
	/* Kromosom T value */
	int T[27][27];
} kromosom;

extern kromosom population[32];

extern char text[TEXT_SIZE];
extern size_t text_length;

extern struct lfsr lfsr1, lfsr2, lfsr3;

#endif
