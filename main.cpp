//
//  main.cpp
//  crypto_trading_platform
//
//  Created by Wesley Stagg on 12/05/2023.
//

#include <iostream>
#include <string>
#include<vector>
#include "menu.h"
#include "OrderBookEntry.h"

int main()
{
    OrderBookEntry obj1{"2020/03/17 17:01:24.884492", "BTC/USD", Order_book_type::bid, 50.056, 200.45};
    OrderBookEntry obj2{"2020/03/17 17:01:24.884492", "BTC/USD", Order_book_type::ask, 3848.33, 29485.3};

    std::vector<OrderBookEntry> entries;
    entries.push_back(obj1);
    entries.push_back(obj2);

    for (unsigned int i{ 0 }; i < entries.size(); ++i)
    {
        std::cout << entries[i].price << std::endl;

    }

    std::cout << "the average price is " << computeAveragePrice(entries) << std::endl;

    while (true)
    {  
        print_menu();

        int user_selection{ get_user_option() };

        process_user_option(user_selection);
    }
    return 0;

}
