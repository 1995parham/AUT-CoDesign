/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 06-03-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#include <stdio.h>
#include <inttypes.h>

#include "defs.h"

int main(int argc, char *argv[])
{
	uint8_t s1, p1;
	uint8_t s2, p2;
	uint8_t s3, p3;

	/* Seed and Polynomial of our LFSR1 :) */
	scanf("%" SCNu8 "%" SCNu8, &s1, &p1);
	GLFSR_init(&lfsr1, p1, s1);
	/* Seed and Polynomial of our LFSR2 :) */
	scanf("%" SCNu8 "%" SCNu8, &s2, &p2);
	GLFSR_init(&lfsr2, p2, s2);
	/* Seed and Polynomial of our LFSR2 :) */
	scanf("%" SCNu8 "%" SCNu8, &s3, &p3);
	GLFSR_init(&lfsr3, p3, s3);
}
