#include "number_util.h"
#include <stdio.h>
#include <ctype.h>

int convert(void)
{
	printf("Enter a digit followed by a space to submit the number: ");
	char part;
	int result = 0;
	while (scanf("%c", &part) != EOF && !isspace(part)) {
		if (part >= '0' && part <= '9') {
			result *= 10;
			result += (part - '0');
		} else {
			break;
		}
	}
	return result;
}
