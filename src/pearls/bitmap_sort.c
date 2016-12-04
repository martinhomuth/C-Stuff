#include "bitvectors.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LENGTH 10000000

int main(void)
{
	long readlong = 0L;
	void *bitmap = bitvector_new(LENGTH);

	while(scanf("%ld", &readlong) != EOF)
		bitvector_set(bitmap, readlong);

	for (long i = 0; i < LENGTH; i++)
		if (bitvector_test(bitmap, i))
			printf("%ld\n", i);

	bitvector_delete(bitmap);
	return 0;
}
