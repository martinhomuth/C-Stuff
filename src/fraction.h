#ifndef FRACTION_H__
#define FRACTION_H__

/**
 * Representation of a fraction.
 */
struct fraction {
	int numerator;   /**< numerator of a fraction */
	int denominator; /**< denominator of a faction */
};

/**
 * @brief Reduces a fraction to its reduced form.
 * @param Fraction The fraction to reduce
 * @return The reduced fraction
 */
struct fraction reduce_fraction(struct fraction fraction);

/**
 * @brief Prints a fraction to stdout
 * @param Fraction The fraction to print
 */
void print_fraction(struct fraction fraction);

#endif /* FRACTION_H__ */
