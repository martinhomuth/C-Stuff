#include <stdio.h>

long gcd(long u, long v)
{
	long t;
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u - v;
	}
	return v;
}

long gcd_ptr(long *u, long *v)
{
	long *t;
	while (*u > 0) {
		if (*u < *v) {
			t = u;
			u = v;
			v = t;
		}
		*u = *u - *v;
	}
	return *v;
}
