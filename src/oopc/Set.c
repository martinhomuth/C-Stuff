/**
 * @file Set.c
 */
#include "Set.h"
#include <assert.h>

#if ! defined MANY || MANY < 1
#define MANY 255 /* impossible index value */
#endif

#define SET_BIT(x) (1 << (x))
#define BIT_IS_SET(x, y) (x & 1 << (y))

const void *Set;
const void *Object;

/**
 * Location to store objects
 *
 * Each Set can contain sizeof(unsigned char) objects
 * -> MANY sets available
 */
static unsigned char heap[MANY];

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
	unsigned char *p; /* &heap[1..] */

	for (p = heap + 1; p < heap + MANY; p++)
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
	unsigned char *item = _item;

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
	unsigned char *set = _set;
	const unsigned char *element = _element;
	int found = 0;

	assert(set > heap && set < heap + MANY);
	assert(*set == MANY); /* if it would not be MANY, something
				 would be wrong */
	assert(element > heap && element < heap + MANY);

	if (*element == MANY) /* allocated but not added */
		*(int *)element = SET_BIT(set - heap);
	else {                  /* already added, but maybe to another
				 set */
		for (int i = 0; i < MANY; i++)
			found |= BIT_IS_SET(*element, i) ? 1 : 0;
		assert(found);
	}

	return (void *)element;
}


/**
 * @brief Looks if its element contains the proper index for the set.
 */
void * find(const void *_set, const void *_element)
{
	const unsigned char *set = _set;
	const unsigned char *element = _element;

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
	unsigned char *element = find(_set, _element);

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
