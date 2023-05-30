#include "order_book_functions.h"
#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> tokenise(std::string csv_line, char seperator)
{
 
	std::vector<std::string> tokens;
	std::string token;

	signed int start{};
	signed int end{};

	start = csv_line.find_first_not_of(seperator, 0);
	do
	{
		end = csv_line.find_first_of(seperator, start);
		
		if (start == csv_line.length() || start == end)
		{
			break;
		}
		if (end >= 0)
		{
			token = csv_line.substr(start, end - start);
		}
		else
		{
			token = csv_line.substr(start, csv_line.length() - start);			
		}
		tokens.push_back(token);
		start = end + 1;
	} while (end != std::string::npos);

	return tokens;
}