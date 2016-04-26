/*
 * In The Name Of God
 * ========================================
 * [] File Name : population.h
 *
 * [] Creation Date : 06-03-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef POPULATION_H
#define POPULATION_H

void population_sort(void);

void pupolation_crossover(const kromosom *p1, const kromosom *p2, kromosom *c1, kromosom *c2);

void pupolation_mutation(kromosom *k);

void population_next(void);

void fill_E(int **e, int total);

void fill_T(void);

#endif
