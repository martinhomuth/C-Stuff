#define _POSIX_C_SOURCE 200809L /* dprintf */
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

#include "bitvectors.h"

#define N 1000000
#define MAX 10000000

long n = N;

/**
 *   $ time bin/gen_numbers
 *  bin/gen_numbers  0.37s user 1.72s system 99% cpu 2.086 total
 *  $ time bin/gen_unique_numbers
 *  bin/gen_unique_numbers  0.44s user 1.76s system 99% cpu 2.202 total
 *  $ time bin/gen_numbers
 *  bin/gen_numbers  0.38s user 1.72s system 99% cpu 2.110 total
 *  $ time bin/gen_unique_numbers
 *  bin/gen_unique_numbers  0.46s user 1.67s system 99% cpu 2.132 total
 *  $ time bin/gen_numbers 4000000
 *  bin/gen_numbers 4000000  1.59s user 6.76s system 99% cpu 8.367 total
 *  $ time bin/gen_unique_numbers 4000000
 *  bin/gen_unique_numbers 4000000  1.69s user 7.06s system 99% cpu 8.764 total
 *
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		n = atoi(argv[1]);

	int file = open("./integers.txt",
			O_CREAT | O_TRUNC | O_WRONLY,
			S_IRWXU | S_IRGRP | S_IROTH);
	if (file < 0)
		perror("open");

	void *vec = bitvector_new(MAX);
	if (!vec)
		fprintf(stderr, "unable to create bitvector\n");

	for (long i = 0; i < n; i++) {
		long num = ((long)rand() * 12354235) % MAX;
		while (bitvector_test(vec, num))
			num = ((long)rand() * rand()) % MAX;
		bitvector_set(vec, num);
	}

	for (long i = 0; i < MAX; i++)
		if (bitvector_test(vec, i))
			dprintf(file, "%ld\n", i);

	bitvector_delete(vec);
	close(file);
	return 0;
}
