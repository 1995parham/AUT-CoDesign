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
	int i, j;

	/* Seed and Polynomial of our LFSR1 :) */
	scanf("%" SCNu8, &s1);
	GLFSR_init(&lfsr1, 0xB8, s1);
	/* Seed and Polynomial of our LFSR2 :) */
	scanf("%" SCNu8, &s2);
	GLFSR_init(&lfsr2, 0xB8, s2);
	/* Seed and Polynomial of our LFSR2 :) */
	scanf("%" SCNu8, &s3);
	GLFSR_init(&lfsr3, 0xB8, s3);

	/* Read RefText */
	FILE *ref = fopen("refText.txt", "r");
	fgets(text, TEXT_SIZE, ref);

	/* Getting the first population :) */
	FILE *keys = fopen("keys", "r");
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 16; j++) {
			fscanf(keys, "%" SCNu8, &population[i].d[j]);
		}
	}

	/* Getting E */
	int total = 1 << 16;
	int e[27][27];
	FILE *etalon = fopen("etalon.txt", "r");
	for (i = 0; i < 28; i++) {
		for (j = 0; j < 28; j++) {
			int num;
			char str[20];
			if (i == 0) {
				fscanf(etalon, "%s", str);
			} else if (j == 0) {
				fscanf(etalon, "%s", str);
			} else {
				fscanf(etalon, "%s %d", str, &num);
				e[i - 1][j - 1] = num;
			}
		}
	}
	fill_E(e, total);
	
	/* Simulation */
	for (i = 0; i < 30; i++) {
		population_next();
	}
	
	for (i = 0; i < 32; i++) {
		printf("[%d] ", i);
		for (j = 0; j < 16; j++) {
			printf("%d ", population[i].d[j]);
		}
		printf("\n");
	}
	
}
