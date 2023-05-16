#include <iostream>
#include "menu.h"

/* Prints menu */
void print_menu()
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
    
    std::cout << "Enter 1-7: " << std::endl;
}

/* Takes user input */
int get_user_option()
{
    int user_selection{};
    std::cin >> user_selection;
    std::cout << user_selection << " chosen." << std::endl;
    
    return user_selection;
}

/* Process user option */
void process_user_option(int user_selection)
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
void print_help()
{
    std::cout << "Help - Your goal is to make as much money as possible!" << std::endl;
}

/* Prints market stats */
void print_market_stats() 
{
    std::cout << "Loading exchange stats..." << std::endl;
}

/* User offer */
void enter_offer()
{
    std::cout << "Make an offer." << std::endl;
}

/* Enter a bid */
void enter_bid()
{
    std::cout << "Make a bid " << std::endl;
}

/* Prints user wallet */
void print_wallet()
{
    std::cout << "Your wallet balance is:" << std::endl;
}

/* Moves to next time frame */
void  next_time_frame()
{
    std::cout << "Loading next time frame..." << std::endl;
}

/* Exits program */
bool exit_program()
{
    std::cout << "Goodbye." << std::endl;
    std::exit(0);
}