#include "Wallet.h"
#include "CSV_reader.h"
#include<iostream>

Wallet::Wallet()
{

}

	
/* Inserts currency to the wallet */
void Wallet::insert_currency(std::string type, double amount)
{
    double balance{};
    if (amount < 0)
    {
        throw std::exception{};
    }
    if (currencies.count(type) == 0 )
    {
        balance = 0;
    }
    else
    {
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;

}

/* Removes currency to the wallet */
bool Wallet::remove_currency(std::string type, double amount)
{
    double balance{};
    if (amount < 0)
    {
        return false;
    }
    if (currencies.count(type) == 0 )
    {
        return false;
    }
    else
    {
        if (contains_currency(type, amount))
        {
            currencies[type] -= amount;
            return true;
        }
        else
        {
            return false;
        }   
    }
}

/* Checks to see if the wallet contains the currency or not */
bool Wallet::contains_currency(std::string type, double amount)
{
    if(currencies.count(type) == 0)
    {
        return false;
    }
    else
    {
        return currencies[type] >= amount;
    }
}

/* Prints a string representaion of the wallet*/
std::string Wallet::to_string()
{
    std::string str;
    for (std::pair<std::string, double> pair : currencies )
    {
        std::string currency {pair.first};
        double amount {pair.second};
        str += currency + " : " + std::to_string(amount) + "\n";
    }

    return str;
}

bool Wallet::can_fufill_order(const Orderbook_entry& order)
{
    std::vector<std::string> curr = CSV_reader::tokenise(order.product, '/');
    
    /* Ask */
    if (order.order_type == Orderbook_type::ask)
    {
        double amount {order.amount};
        std::string currency {curr[0]};
        std::cout << "can_fufill_order " << currency << " : " << amount << std::endl;
        return contains_currency(currency, amount);
    }
    /* Bid*/
    if (order.order_type == Orderbook_type::bid)
    {
        double amount {order.amount * order.price};
        std::string currency {curr[1]};
        std::cout << "can_fufill_order " << currency << " : " << amount << std::endl;
        return contains_currency(currency, amount);
    }

    return false;
    
}


void Wallet::process_sale(Orderbook_entry& sale)
{
    std::vector<std::string> curr = CSV_reader::tokenise(sale.product, '/');

    /* Ask */
    if (sale.order_type == Orderbook_type::ask_sale)
    {
        double outgoing_amount {sale.amount};
        std::string outgoing_currency {curr[0]};
        double incoming_amount {sale.amount * sale.price};
        std::string incoming_currency {curr[1]};

        currencies[incoming_currency] += incoming_amount;
        currencies[outgoing_currency] -= outgoing_amount;
        
    }
    /* Bid*/
    if (sale.order_type == Orderbook_type::bid_sale)
    {
        double incoming_amount {sale.amount};
        std::string incoming_currency {curr[0]};
        double outgoing_amount {sale.amount * sale.price};
        std::string outgoing_currency {curr[1]};

        currencies[incoming_currency] += incoming_amount;
        currencies[outgoing_currency] -= outgoing_amount;
    }
}
