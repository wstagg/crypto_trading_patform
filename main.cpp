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
#include "Order_book_entry.h"
#include "order_book_functions.h"


int main()
{
    Order_book_entry obj1{"2020/03/17 17:01:24.884492", "BTC/USD", Order_book_type::bid, 50.056, 200.45};
    Order_book_entry obj2{"2020/03/17 17:01:24.884492", "BTC/USD", Order_book_type::ask, 3848.33, 29485.3};
    Order_book_entry obj3{ "2020/03/17 17:01:24.884492", "BTC/USD", Order_book_type::ask, 23.4, 29485.3 };
    Order_book_entry obj4{ "2020/03/17 17:01:24.884492", "BTC/USD", Order_book_type::ask, 4748.33, 29485.3 };

    std::vector<Order_book_entry> entries;
    entries.push_back(obj1);
    entries.push_back(obj2);
    entries.push_back(obj3);
    entries.push_back(obj4);

    std::cout << "the average price is " << compute_average_price(entries) << std::endl;
    std::cout << "the lowest price is " << compute_low_price(entries) << std::endl;
    std::cout << "the highest price is " << compute_high_price(entries) << std::endl;

    while (true)
    {  
        print_menu();

        int user_selection{ get_user_option() };

        process_user_option(user_selection);
    }
    return 0;

}
