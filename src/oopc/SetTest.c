#include <stdio.h>

#include "Set.h"
#include "Object.h"
#include "New.h"


int main()
{
	void *s1 = new(Set);
	void *s2 = new(Set);
	void *a = add(s1, new(Object));
	void *a2 = add(s2, a);
	void *b = add(s2, new(Object));
	void *c = new(Object);

	if (contains(s1, a) && contains(s1, b))
		puts("ok");

	if (contains(s1, c))
		puts("contains?");

	if (differ(a, add(s1, a)))
		puts("differ?");

	if (contains(s1, drop(s1, a)))
		puts("drop?");

	delete(drop(s1, b));
	delete(drop(s1, c));
	delete(drop(s2, a2));

	return 0;
}
