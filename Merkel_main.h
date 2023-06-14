#pragma once

#include <vector>
#include "Order_book_entry.h"
#include "Orderbook.h"

class Merkel_main
{
public:
	Merkel_main();
	/* Call this to start the application */
	void init();
	void print_menu();

private:
	Orderbook orderbook{"20200317.csv"};
	int get_user_option();
	void process_user_option(int user_selection);
	void print_help();
	void print_market_stats();
	void enter_offer();
	void enter_bid();
	void print_wallet();
	void next_time_frame();
	bool exit_program();



};

