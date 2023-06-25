#pragma once
#include "Orderbook_entry.h"
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
    std::vector<Orderbook_entry> get_orders(Orderbook_type type, 
                                  std::string product, 
                                  std::string timestamp);

    /* Returns highest bid in the sent set */
    static double get_highest_price(std::vector<Orderbook_entry>& orders);

    /* Returns lowest bid in the sent set */
    static double get_lowest_price(std::vector<Orderbook_entry>& orders);

    /* Returns the earliest time in the orderbook */
    std::string get_earliest_time();

    /* Returns next time after passed timestamp.  */
    /* If no next timestamp exists, loops back to */
    /* first orderbook timestamp                  */
    std::string get_next_time(std::string timestamp);

    /* Returns the change in the past 24 hrs */
    double get_24hr_change(std::vector<Orderbook_entry>& current_day_orders, std::vector<Orderbook_entry>& previous_day_orders); 

    /* Gets the previous days time */
    std::string get_previous_day_time();

    /* Get timestamp time */
    std::string get_time( std::string timestamp);

    void insert_order(Orderbook_entry& order);

    static bool compare_by_timestamp(Orderbook_entry& o1, Orderbook_entry& o2)
    {
        return o1.time_stamp < o2.time_stamp;
    }

private:
    std::vector<Orderbook_entry> orders;
};
