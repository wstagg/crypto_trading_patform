#pragma once
#include "Order_book_entry.h"
#include "CSV_reader.h"
#include <string>
#include <vector>

class Orderbook
{
public:
    /* Orderbook constructor, takes csvfile name */
    Orderbook(std::string csv_file);

    /* Returns a vector of all known products in the orderbook */
    std::vector<std::string> get_known_products();

    /* Returns vectors of orders from set filters */
    std::vector<Order_book_entry> get_orders(Order_book_type type, 
                                  std::string product, 
                                  std::string timestamp);

    /* Returns highest bid in the sent set */
    static double get_highest_price(std::vector<Order_book_entry>& orders);

    /* Returns lowest bid in the sent set */
    static double get_lowest_price(std::vector<Order_book_entry>& orders);

private:
    std::vector<Order_book_entry> orders;
};
