#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define N 1000000
#define MAX 10000000

long n = N;
int binary = 0;

int open_file(void)
{
	int fflags = O_CREAT | O_TRUNC | O_WRONLY;
	int pflags = S_IRWXU | S_IRGRP | S_IROTH;

	if (binary)
		return open("./integers.bin", fflags, pflags);
	else
		return open("./integers.txt", fflags, pflags);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		n = atol(argv[1]);

	if (argc == 3)
		binary = 1;


	int file = open_file();
	if (file < 0)
		perror("open");

	char nl = '\n';
	if (binary)
		for (long i = 0; i < n; i++) {
			unsigned int number = ((long)rand() * 12354235) % INT_MAX;
			if (write(file, &number, sizeof(unsigned int)) == -1)
				perror("write");
			write(file, &nl, 1);
		}
	else
		for (long i = 0; i < n; i++)
			dprintf(file, "%ld\n", ((long)rand() * 12354235) % MAX);

	close(file);
	return 0;
}
