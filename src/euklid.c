#include <stdio.h>

int gcd(int u, int v)
{
	int t;
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

int gcd_info(int u, int v)
{
	int instructions = 0;
	int t;
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
			instructions += 3;
			printf("v: %d\n", v);
		}
		u = u - v;
		instructions += 3;
		printf("u: %d\n", u);
	}
	printf("instructions: %d\n", instructions+1);
	return v;
}


int gcd_ptr(int *u, int *v)
{
	int *t;
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
