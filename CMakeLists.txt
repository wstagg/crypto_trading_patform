cmake_minimum_required(VERSION 3.0.0)
project(crypto_trading_platform VERSION 0.1.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

include(CTest)
enable_testing()

add_executable(crypto_trading_platform main.cpp Merkel_main.cpp order_book_functions.cpp CSV_reader.cpp Orderbook.cpp Orderbook_entry.cpp wallet.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
