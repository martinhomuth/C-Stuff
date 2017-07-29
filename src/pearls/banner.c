/**
 * Given a capital letter as input produces as output an array of
 * characters that graphically depicts that letter.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static char capital_letter;

static char* letter_array[][26] = {
	/* A */
	{       /* lines blanks/Xs */
		"2L6X",
		"2L2X2B2X",
		"2L6X",
		"4L2X2B2X",
		"",
	},
	/* B */
	{
		"2L6X",
		"1L2X2B2X",
		"2L6X",
		"1L2X2B2X",
		"2L6X",
		"",
	},
};

void print_letter_line(const char *line)
{
	int lines;
	const char *ptr;
	char current;
	int num_current;
	sscanf(line, "%dL", &lines);
	for (int i = 0; i < lines; i++) { /* can we make this more
					     efficient? */
		ptr = line+2;
		while (ptr && strcmp(ptr, "")) {
			sscanf(ptr++, "%d", &num_current); /* this
							      might
							      suck */
			sscanf(ptr++, "%c", &current);
			for (int j = 0; j < num_current; j++) {
				if (current == 'B')
					printf(" ");
				else
					printf("X");
			}

		}
		printf("\n");
	}
}

void print_letter(const char letter)
{
	int i = 0;
	char *ptr;
	while (strcmp(letter_array[letter - 'A'][i], "")) {
		ptr = letter_array[letter - 'A'][i];
		print_letter_line(ptr);
		i++;
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

	print_letter(capital_letter);
}
