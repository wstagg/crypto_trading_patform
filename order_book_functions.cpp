#include "order_book_functions.h"
#include "Order_book_entry.h"
#include <vector>
#include <algorithm>
#include <iostream>



/* This computes the average of price of the entries in the order book entry vector */
double compute_average_price(std::vector<Order_book_entry>& entries)
{
    double total{ 0 };

    for (int i{ 0 }; i < entries.size(); ++i)
    {
        total += entries[i].price;
    }

    return total / entries.size();

}

/* This computes the lowest of price of the entries in the order book entry vector */
double compute_low_price(std::vector<Order_book_entry>& entries)
{
    double lowest{ entries[0].price};


    for (int i{ 0 }; i < entries.size(); ++i)
    {
        
        if (entries[i].price < lowest )
        {

            lowest = entries[i].price;
        }
    }
    return lowest;
}

/* This computes the highest of price of the entries in the order book entry vector */
double compute_high_price(std::vector<Order_book_entry>& entries)
{
    double highest{ entries[0].price };


    for (int i{ 0 }; i < entries.size(); ++i)
    {
        if (entries[i].price > highest)
        {

            highest = entries[i].price;
        }
    }
    return highest;
}

