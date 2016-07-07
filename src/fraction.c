#include <stdio.h>

#include "fraction.h"
#include "euklid.h"

struct fraction reduce_fraction(struct fraction fraction)
{
	struct fraction f = fraction;
	int numerator = f.numerator;
	int denominator = f.denominator;
	int gcd_value = gcd(numerator, denominator);
	f.numerator /= gcd_value;
	f.denominator /= gcd_value;
	return f;
}

void print_fraction(struct fraction fraction)
{
	printf("%d/%d\n", fraction.numerator, fraction.denominator);
}
