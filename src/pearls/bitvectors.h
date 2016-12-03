#ifndef __BITVECTORS_H
#define __BITVECTORS_H

/**
 * Allocates a specific number of bits.
 */
void *bitvector_new(int length);

/**
 * Frees a bitvector.
 */
void bitvector_delete(void *vec);

/**
 * Sets a bit in a bitvector.
 */
void bitvector_set(void *vec, int index);
/**
 * Unsets a bit in a bitvector.
 */
void bitvector_unset(void *vec, int index);

#endif
