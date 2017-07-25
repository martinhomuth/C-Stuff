#include <stdio.h>
#include <stdlib.h>
#include "tax_income.h"
#include <assert.h>

void test1(void)
{
	assert(0 == calculate_tax(200));
}

void test2(void)
{
	assert(70.0 == calculate_tax(2700));
}

void test3(void)
{
	assert(112.0 == calculate_tax(3000));
}

int main()
{
	test1();
	test2();
	test3();
	printf("all tests passed\n");
	return EXIT_SUCCESS;
}
