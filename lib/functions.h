#pragma once

#include <string>
#include "mapreduce_export.h"

//!
//! \brief pow2 - square of the value calculation function
//! \param value - value
//! \return square of the value
//!

template<typename T>
inline T pow2(const T &value)
{
    return value * value;
}

//!
//! \brief averageAccumulate - average accumulation function
//! \param avg - current average value
//! \param value - new value
//! \param counter - current count of values
//! \return new average value
//!

MAPREDUCE_EXPORT double averageAccumulate(const double avg, const long value, const size_t counter);

//!
//! \brief splitAndTake
//! \param str - string for spliting
//! \param d - split symbol
//! \param index - required index position
//! \return string from index
//!

MAPREDUCE_EXPORT std::string splitAndTake(const std::string &str, const char d, int index);
