#include "number_util.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>

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

void binary(int digit)
{
	int bits = sizeof(int) * 8;
	char output[bits];
	output[bits] = '\0';
	for (int i = bits; i >= 0; i--) {
		long tmp = pow(2, i);
		if (digit >= tmp) {
			digit -= tmp;
			output[bits - i] = '1';
		} else {
			output[bits - i] = '0';
		}
	}
	printf("%s\n", output);
}
