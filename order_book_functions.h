#pragma once

#include "Orderbook_entry.h"
#include <vector>

double compute_average_price(std::vector<Orderbook_entry>& entries);
double compute_low_price(std::vector<Orderbook_entry>& entries);
double compute_high_price(std::vector<Orderbook_entry>& entries);




