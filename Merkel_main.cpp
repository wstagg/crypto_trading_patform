#include <exception>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "CSV_reader.h"
#include "Merkel_main.h"
#include "Orderbook_entry.h"
#include "Orderbook.h"


Merkel_main::Merkel_main()
{

}

void Merkel_main::init()
{
	previous_day_time = orderbook.get_previous_day_time();
    current_time = orderbook.get_earliest_time();
	
	wallet.insert_currency("BTC", 10.0);
    
    while (true)
    {
        print_menu();
        int user_selection{ get_user_option() };
        process_user_option(user_selection);
    }
    
}

/* Prints menu */
void Merkel_main::print_menu()
{
    // Print help
    std::cout << "\n1. Help:" << std::endl;

    // Print exchange stats
    std::cout << "2. Show Exchange Stats:" << std::endl;

    // Make an offer
    std::cout << "3. Make Ask:" << std::endl;

    // Make bid
    std::cout << "4. Make Bid:" << std::endl;

    // Print wallet
    std::cout << "5. Show Wallet:" << std::endl;

    // Continue
    std::cout << "6. Continue..." << std::endl;

    // Exit
    std::cout << "7. Exit" << std::endl;

    std::cout << "============================" << std::endl;

    std::cout << "Current time: " << current_time << std::endl;

}

/* Takes user menu option*/
int Merkel_main::get_user_option()
{
    int user_selection{0};
    std::string line;
    std::cout << "Enter 1-7: " << std::endl;
    std::getline(std::cin, line );
    
    try {
    user_selection = std::stoi(line);
    } catch (const std::exception& e) 
    {
        
    }
    std::cout<< "You chose: " << user_selection << std::endl;

    return user_selection;
}

/* Process user option */
void Merkel_main::process_user_option(int user_selection)
{
    if (user_selection < 0 || user_selection > 7)
    {
        std::cout << "Invalid choice. Please enter 1-7... " << std::endl;
    }
    if (user_selection == 1)
    {
        print_help();
    }
    if (user_selection == 2)
    {
        print_market_stats();
    }
    if (user_selection == 3)
    {
        enter_ask();
    }
    if (user_selection == 4)
    {
        enter_bid();
    }
    if (user_selection == 5)
    {
        print_wallet();
    }
    if (user_selection == 6)
    {
        next_time_frame();
    }
    if (user_selection == 7)
    {
        exit_program();
    }
}

/* Prints help */
void Merkel_main::print_help()
{
    std::cout << "Help - Your goal is to make as much money as possible!" << std::endl;
}

/* Prints market stats */
void Merkel_main::print_market_stats()
{    
    for (const std::string& p : orderbook.get_known_products())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<Orderbook_entry> current_day_entries = orderbook.get_orders(Orderbook_type::ask, p,   current_time);
        std::vector<Orderbook_entry> previous_day_entries = orderbook.get_orders(Orderbook_type::ask, p,   previous_day_time);

        
        std::cout << "Asks seen: " << current_day_entries.size() << std::endl;
        std::cout << "Max ask: " << Orderbook::get_highest_price(current_day_entries) << std::endl;
        std::cout << "Min ask: " << Orderbook::get_lowest_price(current_day_entries) << std::endl;
        std::cout << "24hr change: " << orderbook.get_24hr_change(current_day_entries, previous_day_entries) << std::endl;
        std::cout << ""<< std::endl;

    }
}

/* Enter ask */
void Merkel_main::enter_ask()
{
    std::cout << "Make an ask - Enter amount: Product, Price, Amount. eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSV_reader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "Bad input" << std::endl;
    }
    else
    {
        try
        {
            Orderbook_entry obe = CSV_reader::strings_to_obe(current_time, 
                                                    tokens[0], 
                                                    Orderbook_type::ask, 
                                                    tokens[1], 
                                                    tokens[2]);
            obe.username = "simuser";
            
            if (wallet.can_fufill_order(obe))
            {
                std::cout << "wallet can fulfill order" << std::endl;
                orderbook.insert_order(obe);
            }
            else
            {   
                std::cout << "wallet cannot fulfill order" << std::endl;
            }
            
        }catch(const std::exception& e)
        {
            std::cout << "Bad input Merkel_main::enter_ask" << std::endl;
        }
    }   
}

/* Enter a bid */
void Merkel_main::enter_bid()
{
    std::cout << "Make an bid - Enter amount: Product, Price, Amount. eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSV_reader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "Bad input" << std::endl;
    }
    else
    {
        try
        {
            Orderbook_entry obe = CSV_reader::strings_to_obe(current_time, 
                                                    tokens[0], 
                                                    Orderbook_type::bid, 
                                                    tokens[1], 
                                                    tokens[2]);
            obe.username = "simuser";
            
            if (wallet.can_fufill_order(obe))
            {
                std::cout << "wallet can fulfill order" << std::endl;
                orderbook.insert_order(obe);
            }
            else
            {   
                std::cout << "wallet cannot fulfill order" << std::endl;
            }
            
        }catch(const std::exception& e)
        {
            std::cout << "Bad input Merkel_main::enter_bid" << std::endl;
        }
    }   
}

/* Prints user wallet */
void Merkel_main::print_wallet()
{
    std::cout << "Your wallet balance is:" << std::endl;
    std::cout << wallet.to_string() << std::endl;
}

/* Moves to next time frame */
void  Merkel_main::next_time_frame()
{
    std::cout << "Loading next time frame..." << std::endl;

    std::vector<Orderbook_entry> sales = orderbook.match_asks_to_bid("ETH/BTC", current_time);
    std::cout << "Sales; " << sales.size() << std::endl;
    for (Orderbook_entry& sale : sales)
    {
        std::cout << "sale price: " << sale.price << " sale ammount:  " << sale.amount << std::endl;
        if (sale.username == "simuser")
        {
            wallet.process_sale(sale);
        }
    }
    current_time = orderbook.get_next_time(current_time);

}

/* Exits program */
bool Merkel_main::exit_program()
{
    std::cout << "Goodbye." << std::endl;
    std::exit(0);
}
