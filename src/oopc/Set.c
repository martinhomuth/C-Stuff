/**
 * @file Set.c
 */
#include "Set.h"
#include <assert.h>

#if ! defined MANY || MANY < 1
#define MANY 10 /* impossible index value */
#endif

const void *Set;
const void *Object;

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

/**
 * @brief Adds an element to a set.
 *
 * Takes an element and adds it to a set. If it is already in the set,
 * the address to that element is returned, the one to the newly
 * inserted element otherwise.
 */
void *add(void *_set, const void *_element)
{
	int *set = _set;
	const int *element = _element;

	assert(set > heap && set < heap + MANY);
	assert(*set == MANY); /* if it would not be MANY, something is
				 wrong */
	assert(element > heap && element < heap + MANY);

	if (*element == MANY) /* allocated but not added */
		*(int *)element = set - heap;
	else                  /* already added */
		assert(*element == set - heap);

	return (void *)element;
}


/**
 * @brief Looks if its element contains the proper index for the set.
 */
void * find(const void *_set, const void *_element)
{
	const int *set = _set;
	const int *element = _element;

	assert(set > heap && set < heap + MANY);
	assert(*set == MANY);
	assert(element > heap && element < heap + MANY);
	assert(*element);

	return *element == set - heap ? (void *) element : 0;
}

/**
 * @brief Converts the result of find() into a truth value.
 */
int contains(const void *_set, const void *_element)
{
	return find(_set, _element) != 0;
}

/**
 * @brief Unassigns an element from a set.
 */
void *drop(void *_set, const void *_element)
{
	int *element = find(_set, _element);

	if (element)
		*element = MANY;

	return element;
}

/**
 * @brief Compares two objects.
 */
int differ(const void *a, const void *b)
{
	return a != b;
}
