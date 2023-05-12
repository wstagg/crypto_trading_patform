//
//  main.cpp
//  crypto_trading_platform
//
//  Created by Wesley Stagg on 12/05/2023.
//

#include <iostream>

int main()
{
    while (true)
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

        /* User input */
        int user_selection{};
        std::cin >> user_selection;

        std::cout << user_selection << " chosen." << std::endl;

        if (user_selection < 0 || user_selection > 7)
        {
            std::cout << "Invalid choice. Please enter 1-7." << std::endl;
        }
        if (user_selection == 1)
        {
            std::cout << "Help - Your goal is to make as much money as possible!" << std::endl;
        }
        if (user_selection == 2)
        {
            std::cout << "Loading exchange stats..." << std::endl;
        }
        if (user_selection == 3)
        {
            std::cout << "Make an offer." << std::endl;
        }
        if (user_selection == 4)
        {
            std::cout << "Make a bid " << std::endl;
        }
        if (user_selection == 5)
        {
            std::cout << "Your wallet balance is:" << std::endl;
        }
        if (user_selection == 6)
        {
            std::cout << "Loading next time frame..." << std::endl;
        }
        if (user_selection == 7)
        {
            std::cout << "Goodbye." << std::endl;
            break;
        }
    }


    return 0;

}
