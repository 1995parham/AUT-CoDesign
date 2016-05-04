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
	uint8_t s1, p1;
	uint8_t s2, p2;
	uint8_t s3, p3;
	int i, j, k;

	/* Seed and Polynomial of our LFSR1 :) */
	scanf("%" SCNu8 "%" SCNu8, &s1, &p1);
	GLFSR_init(&lfsr1, p1, s1);
	/* Seed and Polynomial of our LFSR2 :) */
	scanf("%" SCNu8 "%" SCNu8, &s2, &p2);
	GLFSR_init(&lfsr2, p2, s2);
	/* Seed and Polynomial of our LFSR2 :) */
	scanf("%" SCNu8 "%" SCNu8, &s3, &p3);
	GLFSR_init(&lfsr3, p3, s3);

	/* Getting the first population :) */
	population[0].d[0] = 8;
	population[0].d[1] = 4;
	population[0].d[2] = 6;
	population[0].d[3] = 3;
	population[0].d[4] = 2;
	population[0].d[5] = 1;
	population[0].d[6] = 10;
	population[0].d[7] = 11;
	population[0].d[8] = 15;
	population[0].d[9] = 16;
	population[0].d[10] = 12;
	population[0].d[11] = 14;
	population[0].d[12] = 5;
	population[0].d[13] = 9;
	population[0].d[14] = 13;
	population[0].d[15] = 7;

	population[1].d[0] = 5;
	population[1].d[1] = 9;
	population[1].d[2] = 2;
	population[1].d[3] = 4;
	population[1].d[4] = 8;
	population[1].d[5] = 15;
	population[1].d[6] = 14;
	population[1].d[7] = 12;
	population[1].d[8] = 7;
	population[1].d[9] = 13;
	population[1].d[10] = 1;
	population[1].d[11] = 10;
	population[1].d[12] = 3;
	population[1].d[13] = 6;
	population[1].d[14] = 11;
	population[1].d[15] = 16;

	population[2].d[0] = 1;
	population[2].d[1] = 15;
	population[2].d[2] = 14;
	population[2].d[3] = 12;
	population[2].d[4] = 8;
	population[2].d[5] = 13;
	population[2].d[6] = 10;
	population[2].d[7] = 3;
	population[2].d[8] = 5;
	population[2].d[9] = 9;
	population[2].d[10] = 16;
	population[2].d[11] = 2;
	population[2].d[12] = 6;
	population[2].d[13] = 11;
	population[2].d[14] = 4;
	population[2].d[15] = 7;

	population[3].d[0] = 14;
	population[3].d[1] = 11;
	population[3].d[2] = 5;
	population[3].d[3] = 9;
	population[3].d[4] = 1;
	population[3].d[5] = 2;
	population[3].d[6] = 3;
	population[3].d[7] = 4;
	population[3].d[8] = 7;
	population[3].d[9] = 12;
	population[3].d[10] = 6;
	population[3].d[11] = 10;
	population[3].d[12] = 13;
	population[3].d[13] = 8;
	population[3].d[14] = 15;
	population[3].d[15] = 16;

	population[4].d[0] = 6;
	population[4].d[1] = 5;
	population[4].d[2] = 14;
	population[4].d[3] = 11;
	population[4].d[4] = 15;
	population[4].d[5] = 10;
	population[4].d[6] = 3;
	population[4].d[7] = 4;
	population[4].d[8] = 7;
	population[4].d[9] = 13;
	population[4].d[10] = 9;
	population[4].d[11] = 1;
	population[4].d[12] = 2;
	population[4].d[13] = 8;
	population[4].d[14] = 12;
	population[4].d[15] = 16;

	population[5].d[0] = 12;
	population[5].d[1] = 7;
	population[5].d[2] = 13;
	population[5].d[3] = 9;
	population[5].d[4] = 1;
	population[5].d[5] = 2;
	population[5].d[6] = 3;
	population[5].d[7] = 6;
	population[5].d[8] = 8;
	population[5].d[9] = 15;
	population[5].d[10] = 4;
	population[5].d[11] = 14;
	population[5].d[12] = 16;
	population[5].d[13] = 10;
	population[5].d[14] = 11;
	population[5].d[15] = 5;

	population[6].d[0] = 9;
	population[6].d[1] = 2;
	population[6].d[2] = 3;
	population[6].d[3] = 5;
	population[6].d[4] = 10;
	population[6].d[5] = 4;
	population[6].d[6] = 8;
	population[6].d[7] = 16;
	population[6].d[8] = 15;
	population[6].d[9] = 14;
	population[6].d[10] = 11;
	population[6].d[11] = 6;
	population[6].d[12] = 12;
	population[6].d[13] = 13;
	population[6].d[14] = 1;
	population[6].d[15] = 7;

	population[7].d[0] = 14;
	population[7].d[1] = 12;
	population[7].d[2] = 8;
	population[7].d[3] = 16;
	population[7].d[4] = 15;
	population[7].d[5] = 13;
	population[7].d[6] = 9;
	population[7].d[7] = 1;
	population[7].d[8] = 2;
	population[7].d[9] = 3;
	population[7].d[10] = 6;
	population[7].d[11] = 11;
	population[7].d[12] = 5;
	population[7].d[13] = 4;
	population[7].d[14] = 10;
	population[7].d[15] = 7;

	population[8].d[0] = 13;
	population[8].d[1] = 9;
	population[8].d[2] = 2;
	population[8].d[3] = 3;
	population[8].d[4] = 5;
	population[8].d[5] = 10;
	population[8].d[6] = 4;
	population[8].d[7] = 8;
	population[8].d[8] = 15;
	population[8].d[9] = 14;
	population[8].d[10] = 11;
	population[8].d[11] = 7;
	population[8].d[12] = 6;
	population[8].d[13] = 12;
	population[8].d[14] = 1;
	population[8].d[15] = 16;

	population[9].d[0] = 15;
	population[9].d[1] = 14;
	population[9].d[2] = 12;
	population[9].d[3] = 8;
	population[9].d[4] = 13;
	population[9].d[5] = 10;
	population[9].d[6] = 4;
	population[9].d[7] = 16;
	population[9].d[8] = 11;
	population[9].d[9] = 5;
	population[9].d[10] = 9;
	population[9].d[11] = 2;
	population[9].d[12] = 3;
	population[9].d[13] = 6;
	population[9].d[14] = 7;
	population[9].d[15] = 1;

	population[10].d[0] = 8;
	population[10].d[1] = 15;
	population[10].d[2] = 16;
	population[10].d[3] = 13;
	population[10].d[4] = 12;
	population[10].d[5] = 6;
	population[10].d[6] = 11;
	population[10].d[7] = 14;
	population[10].d[8] = 7;
	population[10].d[9] = 4;
	population[10].d[10] = 10;
	population[10].d[11] = 9;
	population[10].d[12] = 5;
	population[10].d[13] = 3;
	population[10].d[14] = 1;
	population[10].d[15] = 2;

	population[11].d[0] = 16;
	population[11].d[1] = 12;
	population[11].d[2] = 13;
	population[11].d[3] = 10;
	population[11].d[4] = 4;
	population[11].d[5] = 7;
	population[11].d[6] = 8;
	population[11].d[7] = 9;
	population[11].d[8] = 2;
	population[11].d[9] = 3;
	population[11].d[10] = 5;
	population[11].d[11] = 14;
	population[11].d[12] = 11;
	population[11].d[13] = 6;
	population[11].d[14] = 15;
	population[11].d[15] = 1;

	population[12].d[0] = 15;
	population[12].d[1] = 2;
	population[12].d[2] = 4;
	population[12].d[3] = 7;
	population[12].d[4] = 14;
	population[12].d[5] = 11;
	population[12].d[6] = 6;
	population[12].d[7] = 12;
	population[12].d[8] = 8;
	population[12].d[9] = 16;
	population[12].d[10] = 13;
	population[12].d[11] = 10;
	population[12].d[12] = 3;
	population[12].d[13] = 9;
	population[12].d[14] = 5;
	population[12].d[15] = 1;

	population[13].d[0] = 3;
	population[13].d[1] = 15;
	population[13].d[2] = 13;
	population[13].d[3] = 10;
	population[13].d[4] = 16;
	population[13].d[5] = 5;
	population[13].d[6] = 6;
	population[13].d[7] = 11;
	population[13].d[8] = 9;
	population[13].d[9] = 1;
	population[13].d[10] = 2;
	population[13].d[11] = 4;
	population[13].d[12] = 7;
	population[13].d[13] = 8;
	population[13].d[14] = 14;
	population[13].d[15] = 12;

	population[14].d[0] = 7;
	population[14].d[1] = 13;
	population[14].d[2] = 9;
	population[14].d[3] = 1;
	population[14].d[4] = 2;
	population[14].d[5] = 3;
	population[14].d[6] = 5;
	population[14].d[7] = 10;
	population[14].d[8] = 4;
	population[14].d[9] = 8;
	population[14].d[10] = 15;
	population[14].d[11] = 6;
	population[14].d[12] = 12;
	population[14].d[13] = 16;
	population[14].d[14] = 14;
	population[14].d[15] = 11;

	population[15].d[0] = 6;
	population[15].d[1] = 11;
	population[15].d[2] = 5;
	population[15].d[3] = 10;
	population[15].d[4] = 4;
	population[15].d[5] = 8;
	population[15].d[6] = 16;
	population[15].d[7] = 15;
	population[15].d[8] = 14;
	population[15].d[9] = 9;
	population[15].d[10] = 1;
	population[15].d[11] = 2;
	population[15].d[12] = 13;
	population[15].d[13] = 3;
	population[15].d[14] = 12;
	population[15].d[15] = 7;

	population[16].d[0] = 13;
	population[16].d[1] = 10;
	population[16].d[2] = 4;
	population[16].d[3] = 7;
	population[16].d[4] = 3;
	population[16].d[5] = 6;
	population[16].d[6] = 11;
	population[16].d[7] = 5;
	population[16].d[8] = 9;
	population[16].d[9] = 2;
	population[16].d[10] = 8;
	population[16].d[11] = 16;
	population[16].d[12] = 15;
	population[16].d[13] = 1;
	population[16].d[14] = 12;
	population[16].d[15] = 14;

	population[17].d[0] = 12;
	population[17].d[1] = 8;
	population[17].d[2] = 16;
	population[17].d[3] = 15;
	population[17].d[4] = 14;
	population[17].d[5] = 7;
	population[17].d[6] = 13;
	population[17].d[7] = 10;
	population[17].d[8] = 3;
	population[17].d[9] = 6;
	population[17].d[10] = 11;
	population[17].d[11] = 5;
	population[17].d[12] = 9;
	population[17].d[13] = 1;
	population[17].d[14] = 2;
	population[17].d[15] = 4;

	population[18].d[0] = 7;
	population[18].d[1] = 13;
	population[18].d[2] = 9;
	population[18].d[3] = 1;
	population[18].d[4] = 2;
	population[18].d[5] = 3;
	population[18].d[6] = 5;
	population[18].d[7] = 4;
	population[18].d[8] = 8;
	population[18].d[9] = 16;
	population[18].d[10] = 15;
	population[18].d[11] = 14;
	population[18].d[12] = 11;
	population[18].d[13] = 10;
	population[18].d[14] = 6;
	population[18].d[15] = 12;

	population[19].d[0] = 8;
	population[19].d[1] = 16;
	population[19].d[2] = 15;
	population[19].d[3] = 13;
	population[19].d[4] = 10;
	population[19].d[5] = 3;
	population[19].d[6] = 5;
	population[19].d[7] = 9;
	population[19].d[8] = 1;
	population[19].d[9] = 2;
	population[19].d[10] = 6;
	population[19].d[11] = 11;
	population[19].d[12] = 4;
	population[19].d[13] = 7;
	population[19].d[14] = 12;
	population[19].d[15] = 14;

	population[20].d[0] = 11;
	population[20].d[1] = 5;
	population[20].d[2] = 10;
	population[20].d[3] = 3;
	population[20].d[4] = 9;
	population[20].d[5] = 1;
	population[20].d[6] = 2;
	population[20].d[7] = 4;
	population[20].d[8] = 7;
	population[20].d[9] = 13;
	population[20].d[10] = 8;
	population[20].d[11] = 15;
	population[20].d[12] = 6;
	population[20].d[13] = 12;
	population[20].d[14] = 14;
	population[20].d[15] = 16;

	population[21].d[0] = 16;
	population[21].d[1] = 15;
	population[21].d[2] = 13;
	population[21].d[3] = 9;
	population[21].d[4] = 1;
	population[21].d[5] = 2;
	population[21].d[6] = 3;
	population[21].d[7] = 5;
	population[21].d[8] = 10;
	population[21].d[9] = 4;
	population[21].d[10] = 8;
	population[21].d[11] = 14;
	population[21].d[12] = 11;
	population[21].d[13] = 12;
	population[21].d[14] = 7;
	population[21].d[15] = 6;

	population[22].d[0] = 9;
	population[22].d[1] = 6;
	population[22].d[2] = 12;
	population[22].d[3] = 7;
	population[22].d[4] = 14;
	population[22].d[5] = 5;
	population[22].d[6] = 10;
	population[22].d[7] = 4;
	population[22].d[8] = 13;
	population[22].d[9] = 11;
	population[22].d[10] = 2;
	population[22].d[11] = 3;
	population[22].d[12] = 8;
	population[22].d[13] = 16;
	population[22].d[14] = 15;
	population[22].d[15] = 1;

	population[23].d[0] = 11;
	population[23].d[1] = 2;
	population[23].d[2] = 9;
	population[23].d[3] = 13;
	population[23].d[4] = 15;
	population[23].d[5] = 16;
	population[23].d[6] = 8;
	population[23].d[7] = 12;
	population[23].d[8] = 14;
	population[23].d[9] = 7;
	population[23].d[10] = 4;
	population[23].d[11] = 10;
	population[23].d[12] = 3;
	population[23].d[13] = 6;
	population[23].d[14] = 5;
	population[23].d[15] = 1;

	population[24].d[0] = 5;
	population[24].d[1] = 9;
	population[24].d[2] = 2;
	population[24].d[3] = 3;
	population[24].d[4] = 6;
	population[24].d[5] = 12;
	population[24].d[6] = 8;
	population[24].d[7] = 16;
	population[24].d[8] = 15;
	population[24].d[9] = 14;
	population[24].d[10] = 11;
	population[24].d[11] = 10;
	population[24].d[12] = 4;
	population[24].d[13] = 13;
	population[24].d[14] = 1;
	population[24].d[15] = 7;

	population[25].d[0] = 13;
	population[25].d[1] = 10;
	population[25].d[2] = 4;
	population[25].d[3] = 8;
	population[25].d[4] = 15;
	population[25].d[5] = 14;
	population[25].d[6] = 11;
	population[25].d[7] = 6;
	population[25].d[8] = 12;
	population[25].d[9] = 3;
	population[25].d[10] = 5;
	population[25].d[11] = 9;
	population[25].d[12] = 2;
	population[25].d[13] = 16;
	population[25].d[14] = 1;
	population[25].d[15] = 7;

	population[26].d[0] = 6;
	population[26].d[1] = 9;
	population[26].d[2] = 1;
	population[26].d[3] = 2;
	population[26].d[4] = 4;
	population[26].d[5] = 7;
	population[26].d[6] = 14;
	population[26].d[7] = 12;
	population[26].d[8] = 8;
	population[26].d[9] = 15;
	population[26].d[10] = 3;
	population[26].d[11] = 13;
	population[26].d[12] = 11;
	population[26].d[13] = 16;
	population[26].d[14] = 5;
	population[26].d[15] = 10;

	population[27].d[0] = 3;
	population[27].d[1] = 5;
	population[27].d[2] = 9;
	population[27].d[3] = 1;
	population[27].d[4] = 2;
	population[27].d[5] = 4;
	population[27].d[6] = 8;
	population[27].d[7] = 16;
	population[27].d[8] = 15;
	population[27].d[9] = 13;
	population[27].d[10] = 6;
	population[27].d[11] = 12;
	population[27].d[12] = 7;
	population[27].d[13] = 14;
	population[27].d[14] = 10;
	population[27].d[15] = 11;

	population[28].d[0] = 5;
	population[28].d[1] = 10;
	population[28].d[2] = 4;
	population[28].d[3] = 8;
	population[28].d[4] = 16;
	population[28].d[5] = 15;
	population[28].d[6] = 13;
	population[28].d[7] = 9;
	population[28].d[8] = 2;
	population[28].d[9] = 3;
	population[28].d[10] = 6;
	population[28].d[11] = 12;
	population[28].d[12] = 14;
	population[28].d[13] = 11;
	population[28].d[14] = 7;
	population[28].d[15] = 1;

	population[29].d[0] = 1;
	population[29].d[1] = 2;
	population[29].d[2] = 4;
	population[29].d[3] = 8;
	population[29].d[4] = 15;
	population[29].d[5] = 13;
	population[29].d[6] = 10;
	population[29].d[7] = 7;
	population[29].d[8] = 14;
	population[29].d[9] = 12;
	population[29].d[10] = 9;
	population[29].d[11] = 16;
	population[29].d[12] = 3;
	population[29].d[13] = 6;
	population[29].d[14] = 11;
	population[29].d[15] = 5;

	population[30].d[0] = 10;
	population[30].d[1] = 3;
	population[30].d[2] = 5;
	population[30].d[3] = 9;
	population[30].d[4] = 1;
	population[30].d[5] = 2;
	population[30].d[6] = 6;
	population[30].d[7] = 12;
	population[30].d[8] = 7;
	population[30].d[9] = 13;
	population[30].d[10] = 4;
	population[30].d[11] = 8;
	population[30].d[12] = 16;
	population[30].d[13] = 15;
	population[30].d[14] = 14;
	population[30].d[15] = 11;

	population[31].d[0] = 6;
	population[31].d[1] = 12;
	population[31].d[2] = 8;
	population[31].d[3] = 16;
	population[31].d[4] = 15;
	population[31].d[5] = 14;
	population[31].d[6] = 11;
	population[31].d[7] = 7;
	population[31].d[8] = 13;
	population[31].d[9] = 10;
	population[31].d[10] = 3;
	population[31].d[11] = 5;
	population[31].d[12] = 9;
	population[31].d[13] = 2;
	population[31].d[14] = 4;
	population[31].d[15] = 1;


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
