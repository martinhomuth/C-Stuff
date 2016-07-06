#ifndef EUKLID_H__
#define EUKLID_H__

/**
 * @brief Finds the greatest common denominator using euclids algorithm.
 *
 * @param u The first digit
 * @param v The second digit
 * @return The greatest common denominator
 */
long gcd(long u, long v);

/**
 * @brief Finds the greatest common denominator using euclids
 * algorithm and pointers.
 *
 * @param u Pointer to the first digit
 * @param v Pointer to the second digit
 * @return The greatest common denominator
 */
long gcd_ptr(long *u, long *v);

#endif /* EUKLID_H__ */
