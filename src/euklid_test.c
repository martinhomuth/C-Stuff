#include <stdio.h>
#include "euklid.h"
#include <time.h>

int main()
{
	struct timespec ts;
	long start, end;

	printf("Enter two digits: ");
	long x, y;
	while (scanf("%ld %ld", &x, &y) != EOF) {
		timespec_get(&ts, TIME_UTC);
		start = ts.tv_nsec;
		printf("The greatest common denominator is %ld\n", gcd(x, y));
		timespec_get(&ts, TIME_UTC);
		end = ts.tv_nsec;
		printf("took %ld nanoseconds\n", end-start);

		timespec_get(&ts, TIME_UTC);
		start = ts.tv_nsec;
		printf("The greatest common denominator (ptr) is %ld\n", gcd_ptr(&x, &y));
		timespec_get(&ts, TIME_UTC);
		end = ts.tv_nsec;
		printf("took %lld nanoseconds\n", (long long)end-start);
	}
	
}
