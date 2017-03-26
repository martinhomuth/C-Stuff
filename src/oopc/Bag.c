/**
 * @file Bag.c
 */
#include "Set.h"
#include <assert.h>
#include <stdlib.h>

#if ! defined MANY || MANY < 1
#define MANY 10 /* impossible index value */
#endif

struct Set {
	unsigned count;
};

struct Object {
	unsigned count;
	struct Set *in;
};

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

const void *Set = &_Set;
const void *Object = &_Object;

/**
 * @brief Returns an element in heap with value 0
 *
 * This set creation function does not care about the type description
 * and can run out of memory.
 * @param type Points to the type of the object to be created
 * @return Pointer to the new element
 */
void *new(const void *type, ...)
{
	const size_t size = *(const size_t *)type;
	void *p = calloc(1, size);

	assert(p);

	return p;
}

/**
 * @brief Removes an object from the heap
 */
void delete(void *_item)
{
	/* if (!_item) noop */
	free(_item);
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
	struct Set *set = _set;
	struct Object *element = (void *)_element;

	assert(set);
	assert(element);

	if (!element->in)
		element->in = set;
	else
		assert(element->in == set);

	element->count++;
	set->count++;

	return element;
}


/**
 * @brief Looks if its element contains the proper index for the set.
 */
void * find(const void *_set, const void *_element)
{
	const struct Object *element = _element;

	assert(_set);
	assert(element);

	return element->in == _set ? (void *) element : 0;
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
	struct Set *set = _set;
	struct Object *element = find(set, _element);

	if (element) {
		if (--element->count == 0)
			element->in = 0;
		set->count--;
	}
	return element;
}

/**
 * @brief Returns the number of elements in a set.
 */
unsigned count(const void *_set)
{
	const struct Set *set = _set;

	assert(set);
	return(set->count);
}

/**
 * @brief Compares two objects.
 */
int differ(const void *a, const void *b)
{
	return a != b;
}
