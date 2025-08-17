#include <iostream>
#include "functions.h"

//!
//! \brief main - entry point of average and dispersion calculation, reduce stage app
//!

int main(int argc, char *argv[])
{
    std::cout << "reduce stage of big data average/dispersion calculation" << std::endl;

    static const std::string usageString {"usage: reducer [/avg] or /dsp"};

    bool calcDispersion = false;

    if (argc == 2) {
        const std::string flag = argv[1];

        if (flag == "/dsp")
            calcDispersion = true;
        else if (flag != "/avg") {
            std::cout << usageString << std::endl;
            return 1;
        }
    } else if (argc != 1) {
        std::cout << usageString << std::endl;
        return 1;
    }

    double dsp = 0.0;
    double avg = 0.0;
    size_t counter = 0;
    std::string line;

    while (std::getline(std::cin, line)) {
        try {
            const auto value = std::stol(line);

            ++counter;
            avg = averageAccumulate(avg, value, counter);
            if (calcDispersion)
                dsp = averageAccumulate(dsp, pow2(value), counter);
        } catch (std::out_of_range const& ex) {
            std::cout << "invalid parameter: " << line << std::endl;
        }
    }

    if (calcDispersion)
        std::cout << "dispersion: " << dsp - pow2(avg) << std::endl;
    else
        std::cout << "average: " << avg << std::endl;

    return 0;
}
