#include "Orderbook.h"
#include "Order_book_entry.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

/* Orderbook constructor, takes csvfile name */
Orderbook::Orderbook(std::string csv_file)
{
    orders = CSV_reader::read_csv(csv_file);
}

/* Returns a vector of all known products in the orderbook */
std::vector<std::string> Orderbook::get_known_products()
{
    std::map<std::string, bool> product_map;
    for ( const Order_book_entry& e : orders)
    {
        product_map[e.product] = true;
    }
    /* Creates a map data structure to store the product/bool pairs */
    std::vector<std::string> products;
    for (const std::pair<std::string, bool>& product_str_bool_pair: product_map)
    {
        products.push_back(product_str_bool_pair.first);
    }
    return products;
}

/* Returns vectors of orders from set filters */
std::vector<Order_book_entry> Orderbook::get_orders(Order_book_type type, 
                                                    std::string product, 
                                                    std::string timestamp)
{
    std::vector<Order_book_entry> filtered_orders;
    
    for ( Order_book_entry& e : orders)
    {
        if ( e.order_type == type &&
             e.product == product &&
             e.time_stamp == timestamp)
        {
            filtered_orders.push_back(e);
        }
    }
    
    return filtered_orders;
}

/* Returns highest price in the sent set */
double Orderbook::get_highest_price(std::vector<Order_book_entry>& orders)
{
    double max{orders[0].price};

    for ( const Order_book_entry& e : orders)
    {
        if (e.price > max)
        {
            max = e.price;
        }
    }

    return max;
}

/* Returns lowest price in the sent set */
double Orderbook::get_lowest_price(std::vector<Order_book_entry>& orders)
{
    double min{orders[0].price};

     for ( const Order_book_entry& e : orders)
    {
        if (e.price < min)
        {
            min = e.price;
        }
    }

    return min;
}
