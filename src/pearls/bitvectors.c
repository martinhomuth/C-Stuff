/**
 * @file bitvectors.c
 *
 * Implements bit vectors using bitwise logical operations such as \e
 * and, \e or and \e shift.
 */

#include "bitvectors.h"
#include <stdlib.h>
#include <string.h>

#define MASK 0x7

void *bitvector_new(long length)
{
	void *ret = malloc(length / sizeof(char) + 1);
	memset(ret, 0, length / sizeof(char) + 1);
	return ret;
}

void bitvector_delete(void *vec)
{
	if (vec)
		free(vec);
}

void bitvector_set(void *vec, long index)
{
	int offset = index / 8;
	((char *)vec)[offset] |= 1 << (index % 8);
}

void bitvector_unset(void *vec, long index)
{
	int offset = index / 8;
	((char *)vec)[offset] &= ~(1 << (index % 8));
}

int bitvector_test(void *vec, long index)
{
	return ((char *)vec)[index / 8] & (1 << (index & MASK));
}

