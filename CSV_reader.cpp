//
// Created by Wesley Stagg on 06/06/2023.
//
#include "CSV_reader.h"
#include "Orderbook_entry.h"

#include <exception>
#include <fstream>
#include <iostream>
#include <string>



CSV_reader::CSV_reader()
{

}

std::vector<Orderbook_entry> CSV_reader::read_csv(std::string csv_file_name)
{
    std::fstream csv_file (csv_file_name);
    std::string line {};

    std::vector <std::string> tokens;
    std::vector<Orderbook_entry> entries;

    if( csv_file.is_open())
    {
        while(std::getline(csv_file, line))
        {
            try
            {
                Orderbook_entry obj = strings_to_obe(tokenise(line, ','));
                entries.push_back(obj);
            }
            catch(const std::exception& e )
            {
                std::cout << "CSV_reader::read_csv read bad data" << std::endl;
            }
        }
    }

    std::cout << "CSV_reader::read_csv read:" << entries.size() << std::endl;
    return entries;

}

/* Takes string and converts it to order book entry object */
Orderbook_entry CSV_reader::strings_to_obe(std::vector<std::string> tokens)
{
    double price {};
    double amount {};

    if (tokens.size() != 5 )
    {
        std::cout << "Not enough tokens!" << std::endl;
        throw std::exception{};
    }

    /* Converts tokens into correct data types */
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception& e)
    {
        std::cout << "Bad float: " << tokens[3] << "or " << tokens[4] << std::endl;
        throw;
    }
     /* Creates Orderbook_entry object with tokens */
    Orderbook_entry obj {tokens[0],
                          tokens[1],
                          Orderbook_entry::string_to_orderbook_type(tokens[2]),
                          price,
                          amount};
    return obj;
}

/* Tokenises CSV lines */
std::vector<std::string> CSV_reader::tokenise(std::string csv_line, char seperator)
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

Orderbook_entry CSV_reader::strings_to_obe( std::string timestamp,
                                            std::string product,
                                            Orderbook_type orderbook_type,
                                            std::string price_string, 
                                            std::string amount_string)
{
    double price{};
    double amount{};

    try 
    {
        price = std::stod(price_string);
        amount = std::stod(amount_string);
    } catch (const std::exception& e) 
    {
        std::cout << "CSV_reader::strings_to_obe bad float " << price_string << std::endl;
        std::cout << "CSV_reader::strings_to_obe bad float " << amount_string << std::endl;
        throw;
    }

    Orderbook_entry obe {timestamp, product, orderbook_type, price, amount};

    return obe;
}