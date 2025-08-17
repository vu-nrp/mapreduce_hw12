#include <stdexcept>
#include "functions.h"

//!
//! \brief averageAccumulate
//!

double averageAccumulate(const double avg, const long value, const size_t counter)
{
    return avg + (value - avg) / counter;
}

//!
//! \brief splitAndTake
//!

std::string splitAndTake(const std::string &str, const char d, int index)
{
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos) {
        index -= 1;
        if (index == 0)
            return str.substr(start, stop - start);

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    throw std::logic_error("invalid input data structure");
    return std::string();
}
