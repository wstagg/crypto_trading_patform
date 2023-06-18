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

/* Returns the earliest time in the orderbook */
std::string Orderbook::get_previous_day_time()
{
    return orders[0].time_stamp;
}

/* Returns the earliest time in the orderbook */
std::string Orderbook::get_earliest_time()
{
    return orders[10].time_stamp;
}

/* Returns next time after passed timestamp.
If no next timestamp exists, loops back to first orderbook timestamp */
std::string Orderbook::get_next_time(std::string timestamp)
{
    std::string next_timestamp{};

    for (Order_book_entry& e : orders)
    {
        if ( e.time_stamp > timestamp)
        {
            next_timestamp = e.time_stamp;
            break;
        } 
    }

    if ( next_timestamp == "")
    {
        next_timestamp = orders[0].time_stamp;
    }

    return next_timestamp;
}

/* Takes timestamp string and returns just the time */
std::string Orderbook::get_time( std::string timestamp)
{
    std::string time {timestamp[11]};
    return time;
}

/* It takes input of the current days orders and the previous days orders and returns */
/* and returns the difference betweens the current price and previous days price.     */
double Orderbook::get_24hr_change(std::vector<Order_book_entry>& current_day_orders, std::vector<Order_book_entry>& previous_day_orders)
{
    double change {};
    double current_price {};
    double prev_price {};

    for (Order_book_entry& current : current_day_orders)
    {
        for (Order_book_entry& prev : previous_day_orders)
        {
            if( get_time(current.time_stamp) == get_time(prev.time_stamp))
            {
                current_price = current.price;
                prev_price = prev.price;
            }
        }
    } 
    return change = current_price - prev_price;
}


