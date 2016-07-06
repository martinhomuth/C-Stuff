#include <stdio.h>
#include "euklid.h"
#include <time.h>

int main()
{
	struct timespec ts;
	int start, end;

	printf("Enter two digits: ");
	int x, y;
	while (scanf("%d %d", &x, &y) != EOF) {
		timespec_get(&ts, TIME_UTC);
		start = ts.tv_nsec;
		printf("The greatest common denominator is %d\n", gcd(x, y));
		timespec_get(&ts, TIME_UTC);
		end = ts.tv_nsec;
		printf("took %d nanoseconds\n", end-start);

		timespec_get(&ts, TIME_UTC);
		start = ts.tv_nsec;
		printf("The greatest common denominator (ptr) is %d\n", gcd_ptr(&x, &y));
		timespec_get(&ts, TIME_UTC);
		end = ts.tv_nsec;
		printf("took %d nanoseconds\n", end-start);
	}
	
}
