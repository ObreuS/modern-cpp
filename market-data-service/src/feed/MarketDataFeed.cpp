#include "feed/MarketDataFeed.h"

std::vector<Quote> MarketDataFeed::loadSampleQuotes() const {
    return {
        {"EURUSD", 1.0841, 1.0843},
        {"USDTRY", 32.1020, 32.1450},
        {"XAUUSD", 2350.10, 2350.80}
    };
}
