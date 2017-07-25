#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define NUM 50

long income_ranges[] = {
	2200,
	2700,
	3200,
	3700,
	4200,
	/* can be improved with calculation */
	/* index = max(value - 2200, 0) / 500 */
};

static int calculate_index(long income)
{
	return MAX(income - 2200, 0) / 500;
}

/** this has to be defined by hand */
float tax_values[][3] = {
	{    0.0, 0.0,   0.0 }, /* empty */
	{    0.0, .14,   2200.0 },
	{   70.0, .15,   2700.0 },
	{  145.0, .16,   3200.0 },
	{  225.0, .17,   3700.0 },
	/*         ...          */
	{53090.0, .70, 101700.0 },
};

double calculate_tax(long income)
{
	double result;
	int index = calculate_index(income);
	result = tax_values[index][0] + tax_values[index][1] *
		(income - tax_values[index][2]);
	return result;
}

#ifdef STANDALONE_BIN
int main(int argc, char *argv[])
{
	return EXIT_SUCCESS;
}
#endif
