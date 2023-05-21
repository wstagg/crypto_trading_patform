#include "Order_book_entry.h"
#include <vector>



#ifndef order_book_functions_h
#define order_book_functions_h

double compute_average_price(std::vector<Order_book_entry>& entries);
double compute_low_price(std::vector<Order_book_entry>& entries);
double compute_high_price(std::vector<Order_book_entry>& entries);





#endif // !order_book_functions_h


