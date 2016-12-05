#include "customer.h"
#include <stdlib.h>
#include <stdio.h>

customer_ptr create_customer(const char *name, const address* address)
{
	customer_ptr customer = malloc(sizeof *customer);
	if (customer) {
		printf("initializing customer fields... totally.\n");
	}
	return customer;
}

void destroy_customer(customer_ptr customer)
{
	/*
	  perform cleanup of customer-internals beforehand
	 */
	free(customer);
}
