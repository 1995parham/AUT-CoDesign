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

#ifndef POPULATION
#define POPULATION

void population_sort(void);

void pupolation_crossover(const kromosom p1, const kromosom p2, kromosom c1, kromosom c2);

void pupolation_mutation(kromosom k);

#endif