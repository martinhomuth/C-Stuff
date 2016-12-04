#include "bitvectors.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LENGTH 10000000


/**
   $ wc integers.txt
   10000000 10000000 78890375 integers.txt

   $ time sort -n integers.txt >/dev/null
   sort -n integers.txt > /dev/null  23.07s user 0.58s system 280% cpu 8.425 total

   $ time bin/0202_bitmap_sort < integers.txt > /dev/null
   bin/0202_bitmap_sort < integers.txt > /dev/null  2.41s user 0.04s system 99% cpu 2.442 total
*/
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
