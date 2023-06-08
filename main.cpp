//
//  main.cpp
//  crypto_trading_platform
//
//  Created by Wesley Stagg on 12/05/2023.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Order_book_entry.h"
#include "order_book_functions.h"
#include "Merkel_main.h"
#include "CSV_reader.h"


int main()
{
    std::vector<Order_book_entry> order_book = CSV_reader::read_csv("20200317.csv");

   std::string csv_file_name {"20200317.csv"};
   std::fstream csv_file (csv_file_name);
   std::string line {};

   std::vector <std::string> tokens;
   std::vector<Order_book_entry> entries;
   
   if( csv_file.is_open())
   {
      while(std::getline(csv_file, line))
      {
         
          tokens = tokenise(line, ',');

         if (tokens.size() != 5 )
         {
            continue;
         }
         
         /* Converts price token into double  */
         try
         {
             std::string timestamp {tokens[0]};
             std::string product {tokens[1]};
             Order_book_type order_type = Order_book_entry::string_to_orderbook_type(tokens[2]) ;
             double price {std::stod(tokens[3])};
             double amount {std::stod(tokens[4])};

             Order_book_entry obj {timestamp, product, order_type, price,amount};
             entries.push_back(obj);
         }
         catch(const std::exception& e)
         {
            std::cerr << e.what() << '\n';
            continue;
         }
         
         /* Iterates over tokens */
         for ( std::string& l : tokens)
         {
            std::cout << l << std::endl;
         }
      }  
   }
   else 
   {
      std::cout << "Cannot open file." << std::endl; 
   }

   csv_file.close();
    
    // //Merkel_main app;
    // //app.init();

    // std::string test = "thing1,thing2,thing3" ;

    // std::vector<std::string> tokens ;
    // tokens = tokenise(test, ',');

    // for (std::string s : tokens)
    // {
    //     std::cout << s << std::endl;
    // }
  
    return 0;

}
