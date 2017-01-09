#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define TMPFILE "/tmp/peterfile"
#define SIGSIZE 64

char *signature, *word_signature;

int usage(char *progname)
{
	fprintf(stderr, "Usage: %s word dictionary\n", progname);
	exit(EXIT_FAILURE);
}

int get_signature(char *word, char **signature)
{
	int signature_array[26] = {0};
	if (strlen(word) > SIGSIZE)
		return 1;

	char ch;
	while ((ch = *word++)) {
		signature_array[ch - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		if (signature_array[i]) {
			*(*signature)++ = 'a'+i;
			*(*signature)++ = '0'+signature_array[i];
		}

	return 0;
}

int main(int argc, char *argv[])
{
	/*
	 * argv[1]: word to check for anagrams
	 * argv[2]: path to file containing dictionary of words
	 */
	char *word = argv[1];
	signature = calloc(sizeof(char), SIGSIZE);
	word_signature = calloc(sizeof(char), SIGSIZE);

	if (argc != 3)
		usage(argv[0]);

	if (get_signature(word, &word_signature))
		fprintf(stderr, "unable to retrieve signature for %s\n", word);

	fprintf(stdout, "Signature of %s is %s\n", word, word_signature);

	FILE *dictionary = fopen(argv[2], "r");
	if (!dictionary) {
		fprintf(stderr, "Unable to open %s\n", argv[2]);
		perror("");
		return EXIT_FAILURE;
	}

	FILE *tmpfile = fopen(TMPFILE, "w");
	if (!tmpfile) {
		fprintf(stderr, "Unable to open %s\n", TMPFILE);
		return EXIT_FAILURE;
	}

	return 0;
}
