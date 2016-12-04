#ifndef __BITVECTORS_H
#define __BITVECTORS_H

/**
 * Allocates a specific number of bits.
 */
void *bitvector_new(long length);

/**
 * Frees a bitvector.
 */
void bitvector_delete(void *vec);

/**
 * Sets a bit in a bitvector.
 */
void bitvector_set(void *vec, long index);
/**
 * Unsets a bit in a bitvector.
 */
void bitvector_unset(void *vec, long index);

/**
 * Tests whether a bit is set.
 */
int bitvector_test(void *vec, long index);

#endif
