/**
 * Given a capital letter as input produces as output an array of
 * characters that graphically depicts that letter.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static char capital_letter;

static char letter_array[26][8][8] = {
	{
		"   *   ",
		"  ***  ",
		" ** ** ",
		" ** ** ",
		"*******",
		"**   **",
		"**   **",
		"**   **",
	},
	{
		"****** ",
		"**   **",
		"**   **",
		"****** ",
		"****** ",
		"**   **",
		"**   **",
		"****** ",
	},
};

void print_letter(char array[8][8])
{
	for (int i = 0; i < 8; i++) {
		printf("%s\n", array[i]);
	}
}

int prompt_for_letter(void)
{
	char letter;
	printf("Please enter a letter (will be capitalized): ");
	scanf("%c", &letter);
	if (!isalpha(letter))
		return -1;
	capital_letter = toupper(letter);
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc == 2) {
		char letter = *argv[argc - 1];
		if (!isalpha(letter)) {
			fprintf(stderr, "invalid input\n");
			return EXIT_FAILURE;
		}
		capital_letter = toupper(letter);
	} else {
		if (prompt_for_letter())
			fprintf(stderr, "invalid input\n");
	}

	print_letter(letter_array[capital_letter - 'A']);
	print_letter(letter_array['B' - 'A']);
}
