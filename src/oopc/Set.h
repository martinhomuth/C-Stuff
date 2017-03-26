#ifndef _SET_H
#define _SET_H

/**
 * A set is represented in its objects. Each element points to the set.
 */
extern const void *Set;

void *add(void *set, const void *element);
void *find(const void *set, const void *element);
void *drop(void *set, const void *element);
int contains(const void *set, const void *element);

#endif
