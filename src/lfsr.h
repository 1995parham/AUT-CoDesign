/*
 * Galois LFSR software implementation header file
 */
#ifndef LFSR_H
#define LFSR_H

#include <stdint.h>

typedef	uint8_t lfsr_data_t;

struct lfsr {
        lfsr_data_t data,
		    polynomial,
		    mask;
};

struct lfsr *GLFSR_new(lfsr_data_t polynom, lfsr_data_t seed_value);

void GLFSR_init(struct lfsr *glfsr, lfsr_data_t polynom, lfsr_data_t seed_value);

unsigned char GLFSR_next(struct lfsr *glfsr);

#endif
