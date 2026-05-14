cmake_minimum_required(VERSION 3.20)
project(market_data_service VERSION 1.0.0 LANGUAGES CXX)

option(ENABLE_WARNINGS_AS_ERRORS "Treat warnings as errors" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(market_data_core
    src/feed/MarketDataFeed.cpp
    src/processor/QuoteProcessor.cpp
    src/common/Logger.cpp
)

target_compile_options(market_data_core PRIVATE -Wall -Wextra)

if(ENABLE_WARNINGS_AS_ERRORS)
    target_compile_options(market_data_core PRIVATE -Werror)
endif()

add_executable(market-data-service src/main.cpp)
target_link_libraries(market-data-service market_data_core)

enable_testing()
add_executable(unit_tests tests/unit/QuoteProcessorTest.cpp)
target_link_libraries(unit_tests market_data_core)
add_test(NAME unit_tests COMMAND unit_tests)
