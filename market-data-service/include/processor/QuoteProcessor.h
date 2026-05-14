#pragma once
#include "feed/MarketDataFeed.h"

class QuoteProcessor {
public:
    double calculateMidPrice(const Quote& quote) const;
    bool isValidQuote(const Quote& quote) const;
};
