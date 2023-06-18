#include <iostream>
#include <vector>
#include "Merkel_main.h"
#include "Order_book_entry.h"
#include "Orderbook.h"


Merkel_main::Merkel_main()
{

}

void Merkel_main::init()
{
	previous_day_time = orderbook.get_previous_day_time();
    current_time = orderbook.get_earliest_time();
    
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
    std::cout << "3. Make Offer:" << std::endl;

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

    std::cout << "Enter 1-7: " << std::endl;
}

/* Takes user input */
int Merkel_main::get_user_option()
{
    int user_selection{};
    std::cin >> user_selection;
    std::cout << user_selection << " chosen." << std::endl;

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
        enter_offer();
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
        std::vector<Order_book_entry> current_day_entries = orderbook.get_orders(Order_book_type::ask, p,   current_time);
        std::vector<Order_book_entry> previous_day_entries = orderbook.get_orders(Order_book_type::ask, p,   previous_day_time);

        
        std::cout << "Asks seen: " << current_day_entries.size() << std::endl;
        std::cout << "Max ask: " << Orderbook::get_highest_price(current_day_entries) << std::endl;
        std::cout << "Min ask: " << Orderbook::get_lowest_price(current_day_entries) << std::endl;
        std::cout << "24hr change: " << orderbook.get_24hr_change(current_day_entries, previous_day_entries) << std::endl;
        std::cout << ""<< std::endl;

    }
}

/* User offer */
void Merkel_main::enter_offer()
{
    std::cout << "Make an offer." << std::endl;
}

/* Enter a bid */
void Merkel_main::enter_bid()
{
    std::cout << "Make a bid " << std::endl;
}

/* Prints user wallet */
void Merkel_main::print_wallet()
{
    std::cout << "Your wallet balance is:" << std::endl;
}

/* Moves to next time frame */
void  Merkel_main::next_time_frame()
{
    std::cout << "Loading next time frame..." << std::endl;

    //std:: cout << "Current time is "<< orderbook.get_next_time(current_time)<< std::endl;
    current_time = orderbook.get_next_time(current_time);

}

/* Exits program */
bool Merkel_main::exit_program()
{
    std::cout << "Goodbye." << std::endl;
    std::exit(0);
}
