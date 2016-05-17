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
#include "population.h"

int main(int argc, char *argv[])
{
	uint8_t s1;
	uint8_t s2;
	uint8_t s3;
	int i, j, k;

	/* Seed and Polynomial of our LFSR1 :) */
	scanf("%" SCNu8, &s1);
	GLFSR_init(&lfsr1, 0x71, s1);
	/* Seed and Polynomial of our LFSR2 :) */
	scanf("%" SCNu8, &s2);
	GLFSR_init(&lfsr2, 0x71, s2);
	/* Seed and Polynomial of our LFSR2 :) */
	scanf("%" SCNu8, &s3);
	GLFSR_init(&lfsr3, 0x71, s3);

	/* Getting the first population :) */
	FILE *keys = fopen("keys", "r");
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 16; j++) {
			fscanf(keys, "%" SCNu8, &population[i].d[j]);
		}
	}

	/* TODO: Getting E */

	/* Simulation */
	for (i = 0; i < 1024; i++) {
		for (j = 0; j < 32; j++) {
			printf("[%d] ", j);
			for (k = 0; k < 16; k++) {
				printf("%d ", population[j].d[k]);
			}
			printf("\n");
		}
		population_next();
	}
}
