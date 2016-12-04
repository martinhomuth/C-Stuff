#include "bitvectors.h"
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

void test3(void)
{
	void * vec;
	vec = bitvector_new(13);
	if (!vec) {
		fprintf(stderr, "vec is NULL\n");
		exit(1);
	}

	bitvector_set(vec, 7);
	assert(bitvector_test(vec, 7));
	assert(!bitvector_test(vec, 8));

	bitvector_delete(vec);
}

int main()
{
	test1();
	test2();
	test3();
	printf("success\n");
	return 0;
}
