#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <stdlib.h>

#define MAX_NO_OF_ORDERS 42

typedef struct {
	const char *streetname;
	int number;
} address;

typedef struct {
	int order_number;
	int price;
} order;

struct customer{
	const char *name;
	address address;
	size_t no_of_orders;
	order orders[MAX_NO_OF_ORDERS];
};

typedef struct customer* customer_ptr;

customer_ptr create_customer(const char *name, const address* address);
void destroy_customer(customer_ptr customer);

void init_customer(customer_ptr the_customer, const char *name,
		   const address* address);

void place_order(customer_ptr customer, const order* order);

#endif
