/**
 * @file bitvectors.c
 *
 * Implements bit vectors using bitwise logical operations such as \e
 * and, \e or and \e shift.
 */

#include "bitvectors.h"
#include <stdlib.h>
#include <string.h>

void *bitvector_new(int length)
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

void bitvector_set(void *vec, int index)
{
	*(int *)vec |= 1 << index;
}

void bitvector_unset(void *vec, int index)
{
	*(int *)vec = *(int *)vec & ~(1 << index);
}

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void test1(void)
{
	void * vec;
	vec = bitvector_new(13);
	if (!vec) {
		fprintf(stderr, "vec is NULL\n");
		exit(1);
	}
	bitvector_set(vec, 2);
	bitvector_set(vec, 3);
	assert(*(int *)vec == 12);
	bitvector_unset(vec, 3);
	assert(*(int *)vec == 4);

	bitvector_delete(vec);
}

void test2(void)
{
	void * vec;
	vec = bitvector_new(13);
	if (!vec) {
		fprintf(stderr, "vec is NULL\n");
		exit(1);
	}

	for (int i = 0; i < 13; i++)
		bitvector_set(vec, i);
	assert(*(int *)vec == 8191);
	bitvector_unset(vec, 4);
	assert(*(int *)vec == 8175);

	bitvector_delete(vec);
}

int main()
{
	test1();
	test2();
	return 0;
}
