//
// Created by Wesley Stagg on 06/06/2023.
//

#pragma once

#include <string>
#include <vector>
#include "Orderbook_entry.h"


class CSV_reader
{
public:
    CSV_reader();

    static std::vector<Orderbook_entry> read_csv(std::string csv_file_name);
    static std::vector<std::string> tokenise(std::string, char seperator);

    static Orderbook_entry strings_to_obe( std::string timestamp,
                                            std::string product,
                                            Orderbook_type orderbook_type,
                                            std::string price_string, 
                                            std::string amount_string);


private:
    static Orderbook_entry strings_to_obe(std::vector<std::string> strings);

};


