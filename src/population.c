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
#include <pthread.h>

kromosom population[32];

struct lfsr lfsr1, lfsr2, lfsr3;

static int E[27][27];
static int E_total;

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
				k1->T[i][j] * E_total);
			sum2 += abs(
				E[i][j] * (int) text_length -
				k2->T[i][j] * E_total);
		}
	}

	return sum1 - sum2;
}

void population_sort(void)
{
	fill_T();
	qsort(population, 32, sizeof(kromosom), population_sort_fn);
}

void fill_E(int e[27][27], int total)
{
	int i, j;

	E_total = total;

	for (i = 0; i < 27; i++) {
		for (j = 0; j < 27; j++) {
			E[i][j] = e[i][j];
		}
	}
}

void *fill_T_fn(void *input) {
	int j;
	long i = (long) input;
	
	char decoded_text[text_length + 1];

	decode_text(&population[i], decoded_text);

	for (j = 0; j < text_length; j++) {
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
		population[i].T[a][b]++;
	}

	pthread_exit(NULL);
}

void fill_T(void)
{
	long i, j, k;

	for (i = 0; i < 32; i++)
		for (j = 0; j < 27; j++)
			for (k = 0; k < 27; k++)
				population[i].T[j][k] = 0;

	/* Using thread to simulate hardware :D */
	pthread_t tids[32];
	pthread_attr_t attr;
	/* Initialize and set thread detached attribute */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for (i = 0; i < 32; i++) {
		pthread_create(&tids[i], &attr, fill_T_fn, (void *) i);
		pthread_join(tids[i], NULL);
	}

	pthread_attr_destroy(&attr);
	//for (i = 0; i < 32; i++)
	//	pthread_join(tids[i], NULL);
}

void population_next(void)
{
	long i;

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
	int flags1[16], flags2[16];

	/* get the alpha from LFSR1 */
	alpha = lfsr1.data;
	GLFSR_next(&lfsr1);

	alpha &= 0x0F;
	alpha++;

	for (i = 0; i < 16; i++) {
		flags1[i] = 0;
		flags2[i] = 0;
	}

	for (i = 0; i < alpha; i++) {
		c1->d[i] = p1->d[i];
		flags1[p1->d[i]] = 1;

		c2->d[i] = p2->d[i];
		flags2[p2->d[i]] = 1;
	}

	for (i = 0; i < 16; i++) {
		int flag1 = 1;
		int flag2 = 1;

		for (j = 0; j < 16 && flag1; j++) {
			int index = p2->d[j];
			if (!flags1[index]){
				c1->d[i] = index;
				flags1[index] = 1;
				flag1 = 0;
			}
		}

		for (j = 0; j < 16 && flag2; j++) {
			int index = p1->d[j];
			if (!flags2[index]){
				c2->d[i] = index;
				flags2[index] = 1;
				flag2 = 0;
			}
		}
	}
}

void population_mutation(kromosom *k)
{
	uint8_t p;
	uint8_t indicator, i, j;

	/* get p from LFSR2 */
	p = lfsr2.data;
	GLFSR_next(&lfsr2);

	if (p >= 64)
		return;

	/* get indicator from LFSR3 */
	indicator = lfsr3.data;
	GLFSR_next(&lfsr3);

	i = (uint8_t) (indicator & 0x0F);
	j = (uint8_t) (indicator >> 4);

	if (i == j)
		return;

	k->d[i] = k->d[i] + k->d[j];
	k->d[j] = k->d[i] - k->d[j];
	k->d[i] = k->d[i] - k->d[j];

}
