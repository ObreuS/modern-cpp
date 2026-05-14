#pragma once
#include <string>
#include <vector>

struct Quote {
    std::string symbol;
    double bid;
    double ask;
};

class MarketDataFeed {
public:
    std::vector<Quote> loadSampleQuotes() const;
};
