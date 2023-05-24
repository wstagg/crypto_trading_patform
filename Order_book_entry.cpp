#include "Order_book_entry.h"

Order_book_entry::Order_book_entry(std::string _time_stamp, std::string _product, Order_book_type _order_type, double _price, double _amount)
	
	:time_stamp(_time_stamp), 
	product(_product),
	order_type(_order_type), 
	price(_price), 
	amount(_amount)
{
	
}
