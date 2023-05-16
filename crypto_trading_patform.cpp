//
//  main.cpp
//  crypto_trading_platform
//
//  Created by Wesley Stagg on 12/05/2023.
//

#include <iostream>
#include "menu.h"

int main()
{
    while (true)
    {  
        print_menu();

        int user_selection{ get_user_option() };

        process_user_option(user_selection);
    }
    return 0;

}
