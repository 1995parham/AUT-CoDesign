/*
 * In The Name Of God
 * ========================================
 * [] File Name : population.c
 *
 * [] Creation Date : 06-03-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#include "defs.h"

#include <stdlib.h>
#include <stdint.h>

kromosom population[32];

void population_sort(void)
{
}

static int population_sort_fn(const void *a, const void *b)
{
}

void population_crossover(const kromosom p1, const kromosom p2, kromosom c1, kromosom c2)
{
	uint8_t alpha;
	int i, j;
	int index1, index2;

	/* get the alpha from LFSR */

	alpha &= 0x0F;

	for (i = 0; i < alpha; i++) {
		c1[i] = p1[i];
		c2[i] = p2[i];
	}

	index1 = alpha;
	index2 = alpha;
	for (i = 0; i < 16; i++) {
		int flag1 = 0;
		int flag2 = 0;

		for (j = 0; j < alpha; j++) {
			if (c1[j] == p2[i]) {
				flag1 = 1;
			}
			if (c2[j] == p1[i]) {
				flag2 = 1;
			}
		}
		if (!flag1) {
			c1[index1] = p2[i];
			index1++;
		}
		if (!flag2) {
			c2[index2] = p1[i];
			index2++;
		}
	}
}

void population_mutation(kromosom k)
{
}
