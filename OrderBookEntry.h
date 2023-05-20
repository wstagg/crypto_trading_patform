#pragma once
#include <string>

enum class Order_book_type {bid, ask};


class OrderBookEntry
{

public:

	OrderBookEntry(std::string _time_stamp, std::string _product, Order_book_type _order_type, double _price, double _amount);

	std::string time_stamp;
	std::string product;
	Order_book_type order_type;
	double price;
	double amount;
	

};

