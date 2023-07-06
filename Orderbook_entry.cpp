#include "Orderbook_entry.h"

Orderbook_entry::Orderbook_entry(std::string _time_stamp, std::string _product, Orderbook_type _order_type, double _price, double _amount, std::string _username)
	
	:time_stamp(_time_stamp), 
	product(_product),
	order_type(_order_type), 
	price(_price), 
	amount(_amount),
    username(_username)
{
	
}

Orderbook_type Orderbook_entry::string_to_orderbook_type(const std::string &s)
{
    if ( s == "ask")
    {
        return Orderbook_type::ask;
    }
    if ( s == "bid")
    {
        return Orderbook_type::bid;
    }
    return Orderbook_type::unknown;
}