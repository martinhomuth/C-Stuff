#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define TMPFILE "/tmp/peterfile"
#define SIGSIZE 64
#define MAXWORD 128

char *signature, *word_signature;

int usage(char *progname)
{
	fprintf(stderr, "Usage: %s word dictionary\n", progname);
	exit(EXIT_FAILURE);
}

int get_signature(char *word, char **signature)
{
	int signature_array[26] = {0};
	char *ptr = *signature;

	if (strlen(word) > SIGSIZE)
		return 1;

	char ch;
	while ((ch = *word++)) {
		signature_array[ch - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		if (signature_array[i]) {
			*ptr++ = 'a'+i;
			*ptr++ = '0'+signature_array[i];
		}
	*ptr = '\0';
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

	printf("%s has the following anagrams in the dictionary:\n", word);

	FILE *dictionary = fopen(argv[2], "r");
	if (!dictionary) {
		fprintf(stderr, "Unable to open %s\n", argv[2]);
		perror("");
		return EXIT_FAILURE;
	}

	char buf[MAXWORD];
	while (fscanf(dictionary, "%s ", buf) != EOF) {
		if (get_signature(buf, &signature))
			fprintf(stderr, "unable to retrieve signature for %s\n", word);

		if (!strcmp(signature, word_signature))
			printf(" %s", buf);
	}
	printf("\n");

	free(signature);
	free(word_signature);
	return 0;
}
