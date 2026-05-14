#include "feed/MarketDataFeed.h"
#include "processor/QuoteProcessor.h"
#include "common/Logger.h"
#include <iostream>

int main() {
    Logger::info("market-data-service starting");

    MarketDataFeed feed;
    QuoteProcessor processor;

    for (const auto& quote : feed.loadSampleQuotes()) {
        if (!processor.isValidQuote(quote)) {
            Logger::warn("invalid quote received for " + quote.symbol);
            continue;
        }

        std::cout << quote.symbol
                  << " midPrice="
                  << processor.calculateMidPrice(quote)
                  << std::endl;
    }

    Logger::info("market-data-service completed");
    return 0;
}
