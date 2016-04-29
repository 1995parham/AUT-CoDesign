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
#include "lfsr.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

kromosom population[32];

struct lfsr lfsr1, lfsr2, lfsr3;

static int E[27][27];
static int E_total;
static int T[32][27][27];

static int population_sort_fn(const void *a, const void *b)
{
	const kromosom *k1 = (const kromosom *) a;
	const kromosom *k2 = (const kromosom *) b;

	int i, j;
	unsigned int sum1 = 0;
	unsigned int sum2 = 0;

	for (i = 0; i < 27; i++) {
		for (j = 0; j < 27; j++) {
			sum1 += abs(
				E[i][j] * (int) text_length -
				T[k1->i][i][j] * E_total);
			sum2 += abs(
				E[i][j] * (int) text_length -
				T[k2->i][i][j] * E_total);
		}
	}

	return sum1 - sum2;
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
	int i, j, k;

	for (i = 0; i < 32; i++)
		for (j = 0; j < 27; j++)
			for (k = 0; k < 27; k++)
				T[i][j][k] = 0;

	for (i = 0; i < 32; i++) {
		population[i].i = (uint8_t) i;

		char decoded_text[text_length + 1];

		decode_text(&population[i], decoded_text);

		for (j = 0; j < text_length - 1; j++) {
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
			printf("[%d] %d: %x %x %d %d\n", i, j, decoded_text[j], decoded_text[j+ 1], a, b);
			T[i][a][b]++;
		}
	}
}

void population_next(void)
{
	int i;

	/* population sorting */
	population_sort();

	/* crossover operator */
	for (i = 0; i < 16; i += 2)
		population_crossover(&population[i], &population[i + 1],
			&population[i + 16], &population[i + 1 + 16]);

	/* mutation operator */
	for (i = 0; i < 32; i++)
		population_mutation(&population[i]);
}

void population_crossover(const kromosom *p1, const kromosom *p2, kromosom *c1,
	kromosom *c2)
{
	uint8_t alpha;
	int i, j;
	int index1, index2;

	/* get the alpha from LFSR1 */
	alpha = GLFSR_next(&lfsr1);

	alpha &= 0x0F;

	for (i = 0; i < alpha; i++) {
		c1->d[i] = p1->d[i];
		c2->d[i] = p2->d[i];
	}

	index1 = alpha;
	index2 = alpha;
	for (i = 0; i < 16; i++) {
		int flag1 = 0;
		int flag2 = 0;

		for (j = 0; j < alpha; j++) {
			if (c1->d[j] == p2->d[i]) {
				flag1 = 1;
			}
			if (c2->d[j] == p1->d[i]) {
				flag2 = 1;
			}
		}
		if (!flag1) {
			c1->d[index1] = p2->d[i];
			index1++;
		}
		if (!flag2) {
			c2->d[index2] = p1->d[i];
			index2++;
		}
	}
}

void population_mutation(kromosom *k)
{
	uint8_t p;
	uint8_t indicator, i, j;

	/* get p from LFSR2 */
	p = GLFSR_next(&lfsr2);

	if (p >= 64)
		return;

	/* get indicator from LFSR3 */
	indicator = GLFSR_next(&lfsr3);

	i = (uint8_t) (indicator & 0x0F);
	j = (uint8_t) (indicator & 0xF0);

	k->d[i] = k->d[i] + k->d[j];
	k->d[j] = k->d[i] - k->d[j];
	k->d[i] = k->d[i] - k->d[j];
}
