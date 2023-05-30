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


int main()
{
   std::string csv_file_name {"20200317.csv"};
   std::fstream csv_file (csv_file_name);
   std::string line {};

   double price {};
   double amount {};
   
   if( csv_file.is_open())
   {
      while(std::getline(csv_file, line))
      {
         
         std::vector <std::string> tokens = tokenise(line, ',');

         if (tokens.size() != 5 )
         {
            continue;
         }
         
         /* Converts price token into double  */
         try
         {
            price = std::stod(tokens[3]);   
         }
         catch(const std::exception& e)
         {
            std::cerr << e.what() << '\n';
            continue;
         }

         /* Converts amount token into double */
         try
         {
            amount = std::stod(tokens[4]);
         }
         catch(const std::exception& e)
         {
            std::cerr << e.what() << '\n';
            continue;
         }
         
         /* Iterates over tokens */
         for ( std::string l : tokens)
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
