//
// Created by Wesley Stagg on 06/06/2023.
//

#pragma once

#include <string>
#include <vector>
#include "Order_book_entry.h"


class CSV_reader
{
public:
    CSV_reader();

    static std::vector<Order_book_entry> read_csv(std::string csv_file_name);

private:
    static std::vector<std::string> tokenise(std::string, char seperator);
    static Order_book_entry strings_to_obe(std::vector<std::string> strings);

};


