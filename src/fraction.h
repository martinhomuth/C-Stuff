#ifndef FRACTION_H__
#define FRACTION_H__

struct fraction {
	int numerator;
	int denominator;
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
