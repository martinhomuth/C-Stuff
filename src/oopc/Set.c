/**
 * @file Set.c
 */
#include "Set.h"
#include <assert.h>

#if ! defined MANY || MANY < 1
#define MANY 10
#endif

/**
 * Location to store objects
 */
static int heap[MANY];

/**
 * @brief Returns an element in heap with value 0
 *
 * This set creation function does not care about the type description
 * and can run out of memory.
 * @param type Points to the type of the object to be created
 * @return Pointer to the new heap element
 */
void *new(const void *type, ...)
{
	int *p; /* &heap[1..] */

	for (p = heap + 1; p < heap + MANY; ++p)
		if (!*p)
			break;
	assert(p < heap + MANY);
	*p = MANY;
	return p;
}

/**
 * @brief Removes an object from the heap
 */
void delete(void *_item)
{
	int *item = _item;

	if (item) {
		assert(item > heap && item < heap + MANY);
		*item = 0;
	}
}

