#include <stdio.h>
#include "fraction.h"

int main()
{
	struct fraction f = { .numerator = 34, .denominator = 8 };
	printf("normal: ");
	print_fraction(f);
	printf("reduced: ");
	reduce_fraction(f);
	print_fraction(f);
	return 0;
}
