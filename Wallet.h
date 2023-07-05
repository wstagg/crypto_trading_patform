#pragma once
#include <string>
#include <map>
#include"Orderbook_entry.h"

class Wallet
{
public:
    Wallet();
	
	/* Inserts currency to the wallet */
	void insert_currency(std::string type, double amount);
	
	/* Removes currency to the wallet */
	bool remove_currency(std::string type, double amount);
	
	/* Prints a string representaion of the wallet*/
	std::string to_string();

	/* Checks whether wallet can cope with ask or bid */
	bool can_fufill_order(const Orderbook_entry& order);

	/* Checks to see if the wallet contains the currency or not */
	bool contains_currency(std::string type, double amount);
	
    

private:
	std::map<std::string,double> currencies;

};
