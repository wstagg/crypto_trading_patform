#pragma once

#include "Order_book_entry.h"
#include <vector>

double compute_average_price(std::vector<Order_book_entry>& entries);
double compute_low_price(std::vector<Order_book_entry>& entries);
double compute_high_price(std::vector<Order_book_entry>& entries);




