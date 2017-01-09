#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int usage(char *progname)
{
	fprintf(stderr, "Usage: %s word dictionary\n", progname);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	/*
	 * argv[1]: word to check for anagrams
	 * argv[2]: path to file containing dictionary of words
	 */
	//	char *word = argv[1];

	if (argc != 3)
		usage(argv[0]);

	FILE *dictionary = fopen(argv[2], "r");
	if (!dictionary) {
		fprintf(stderr, "Unable to open %s\n", argv[2]);
		perror("");
		return EXIT_FAILURE;
	}

	int tempfd = mkstemp("anagramXXXXXX");
	if (tempfd == -1) {
		perror("mkostemp");
		return EXIT_FAILURE;
	}
	return 0;
}
