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

#define TEXT_SIZE 16

#include <stdint.h>

#include "lfsr.h"

typedef uint8_t kromosom[16];

extern kromosom population[32];

extern char text[TEXT_SIZE];

extern struct lfsr lfsr1, lfsr2, lfsr3;

#endif
