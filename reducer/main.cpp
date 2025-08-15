#include <string>
#include <iostream>

template<typename T>
inline T pow2(const T &value)
{
    return value * value;
}

int main()
{
    size_t counter = 0;
    double avgSum = 0.0;
    double sqrSum = 0.0;
    std::string line;

    while (true) {

        const auto value = std::stol(line);

        counter += 1;
        avgSum += value;
        sqrSum += pow2(value);
    }

    // среднеарифметическое
    const auto avg = avgSum / counter;

    std::cout << "dispersion: " << sqrSum / counter - pow2(avg) << std::endl;

    return 0;
}
