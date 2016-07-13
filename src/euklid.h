#ifndef EUKLID_H__
#define EUKLID_H__

/**
 * @brief Finds the greatest common denominator using euclids algorithm.
 *
 * @param u The first digit
 * @param v The second digit
 * @return The greatest common denominator
 */
int gcd(int u, int v);

/**
 * @brief Finds the greatest common denominator using euclids
 * algorithm and prints every value of u and v.
 *
 * @param u The first digit
 * @param v The second digit
 * @return The greatest common denominator
 */
int gcd_info(int u, int v);

/**
 * @brief Finds the greatest common denominator using euclids
 * algorithm and pointers.
 *
 * @param u Pointer to the first digit
 * @param v Pointer to the second digit
 * @return The greatest common denominator
 */
int gcd_ptr(int *u, int *v);

#endif /* EUKLID_H__ */
