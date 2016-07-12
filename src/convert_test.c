#include "number_util.h"

#include <stdio.h>

int main()
{
	int digit = convert();
	printf("The number is %d\n", digit);
	binary(digit);
	return 0;
}
