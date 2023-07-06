#pragma once

#include <string>

enum class Orderbook_type {bid, ask, sale, unknown, ask_sale, bid_sale};

class Orderbook_entry
{

public:

	Orderbook_entry(std::string _time_stamp, std::string _product, Orderbook_type _order_type, double _price, double _amount, std::string _username = "dataset");

	std::string time_stamp;
	std::string product;
	Orderbook_type order_type;
	double price;
	double amount;
	std::string username;

    static Orderbook_type string_to_orderbook_type (const std::string& s);
};

