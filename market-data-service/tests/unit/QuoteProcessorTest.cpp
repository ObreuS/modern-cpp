#include "processor/QuoteProcessor.h"
#include <cassert>
#include <cmath>
#include <iostream>

int main() {
    QuoteProcessor processor;

    Quote validQuote{"EURUSD", 1.10, 1.20};
    assert(processor.isValidQuote(validQuote));
    assert(std::fabs(processor.calculateMidPrice(validQuote) - 1.15) < 0.0001);

    Quote invalidQuote{"BROKEN", 5.0, 4.0};
    assert(!processor.isValidQuote(invalidQuote));

    std::cout << "QuoteProcessorTest passed" << std::endl;
    return 0;
}
