#ifndef _OBJECT_H
#define _OBJECT_H

/**
 * Representation of anything interesting
 */
extern const void *Object;

/**
 * @brief Compares two objects with each other
 */
int differ(const void *a, const void *b);

#endif
