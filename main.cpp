//
//  main.cpp
//  crypto_trading_platform
//
//  Created by Wesley Stagg on 12/05/2023.
//

#include <iostream>
#include <string>
#include<vector>
#include "Order_book_entry.h"
#include "order_book_functions.h"
#include "Merkel_main.h"


int main()
{
   
    
    //Merkel_main app;
    //app.init();

    std::string test = "thing1,thing2,thing3" ;

    std::vector<std::string> tokens ;
    tokens = tokenise(test, ',');

    for (std::string s : tokens)
    {
        std::cout << s << std::endl;
    }
  
    return 0;

}
