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
#include "text.h"
#include "population.h"

#include <stdlib.h>
#include <stdint.h>

kromosom population[32];

static int E[27][27];
static int E_total;
static int T[32][27][27];

static int population_sort_fn(const void *a, const void *b)
{
	const kromosom *k1 = (const kromosom *) a;
	const kromosom *k2 = (const kromosom *) b;
}

void population_sort(void)
{
	fill_T();
	qsort(population, 32, sizeof(kromosom), population_sort_fn);
}

void fill_E(int **e, int total)
{
	int i, j;

	E_total = total;

	for (i = 0; i < 27; i++) {
		for (j = 0; j < 27; j++) {
			E[i][j] = e[i][j];
		}
	}
}

void fill_T(void)
{
	int i, j;

	for (i = 0; i < 32; i++) {
		char decoded_text[TEXT_SIZE];
		
		decode_text(population[i], decoded_text);
	
		for (j = 0; j < TEXT_SIZE; j++) {
			int a = 0;
			int b = 0;
			
			if (decoded_text[j] == ' ')
				a = 26;
			else
				a = decoded_text[j] - 'a';
			
			if (decoded_text[j + 1] == ' ')
				b = 26;
			else
				b = decoded_text[j + 1] - 'a';
			T[i][a][b]++;
		}
	}
}

void population_crossover(const kromosom p1, const kromosom p2, kromosom c1, kromosom c2)
{
	uint8_t alpha;
	int i, j;
	int index1, index2;

	/* get the alpha from LFSR1 */

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
	uint8_t p;
	uint8_t indicator, i, j;

	/* get p from LFSR2 */
	
	if (p >= 64)
		return;

	/* get indicator from LFSR3 */

	i = indicator & 0x0F;
	j = indicator & 0xF0;

	k[i] = k[i] + k[j];
	k[j] = k[i] - k[j];
	k[i] = k[i] - k[j];
}
