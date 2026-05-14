#include "processor/QuoteProcessor.h"

double QuoteProcessor::calculateMidPrice(const Quote& quote) const {
    return (quote.bid + quote.ask) / 2.0;
}

bool QuoteProcessor::isValidQuote(const Quote& quote) const {
    return !quote.symbol.empty() && quote.bid > 0.0 && quote.ask > 0.0 && quote.ask >= quote.bid;
}
