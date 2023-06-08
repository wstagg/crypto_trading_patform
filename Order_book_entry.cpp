#include "Order_book_entry.h"

Order_book_entry::Order_book_entry(std::string _time_stamp, std::string _product, Order_book_type _order_type, double _price, double _amount)
	
	:time_stamp(_time_stamp), 
	product(_product),
	order_type(_order_type), 
	price(_price), 
	amount(_amount)
{
	
}

Order_book_type Order_book_entry::string_to_orderbook_type(const std::string &s)
{
    if ( s == "ask")
    {
        return Order_book_type::ask;
    }
    if ( s == "bid")
    {
        return Order_book_type::bid;
    }
    return Order_book_type::unknown;
}