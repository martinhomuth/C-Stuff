#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

#define N 1000000
#define MAX 10000000

long n = N;

int main(int argc, char *argv[])
{
	if (argc == 2)
		n = atoi(argv[1]);


	int file = open("./integers.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | S_IRGRP | S_IROTH);
	if (file < 0)
		perror("open");

	for (long i = 0; i < n; i++)
		dprintf(file, "%ld\n", ((long)rand() * 12354235) % MAX);

	close(file);
	return 0;
}
