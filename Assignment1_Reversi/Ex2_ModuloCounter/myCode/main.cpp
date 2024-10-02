// Standard (system) header files
#include <iostream>
#include <cmath>
#include "ModuloNCounter.h"
#include <limits>

/**
 * @brief Prettier line
 * @return the maximum value of the counter
 */
int lineBreakFrequency(int counterType) {
    return (counterType == 2) ? 16 : counterType;
}
// Main program
int main() {
    std::cout << "Ex2_ModuloCounter started.\n";
    std::cout << "Please enter the parameters for the counter:\n";

    int numberOfDigits;
    bool inputSuccess;

    do	{
        std::cout << "Enter number of digits of the counter: ";
        inputSuccess = static_cast<bool>(std::cin >> numberOfDigits);

        if (!inputSuccess || numberOfDigits <= 0) {
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
    } while (!inputSuccess || numberOfDigits <= 0);


    bool isValidCounterType;
    int counterType;
    do {
        std::cout << "Enter counter type (2/8/10/16): (2, 8, 10, 16): ";
        inputSuccess = static_cast<bool>(std::cin >> counterType);

        if (!inputSuccess) {
            std::cout << "Invalid input. Please enter a numeric value.\n";
            continue;
        }

        isValidCounterType = (counterType == 2 || counterType == 8
        		|| counterType == 10 || counterType == 16);

        if (!isValidCounterType) {
            std::cout << "Please enter valid options: 2, 8, 10, or 16.\n";
        }
    } while (!inputSuccess || !isValidCounterType);


    ModuloNCounter counter(numberOfDigits, counterType);
    counter.print(PRINT_OPTIONS::COUNTER_NAME);

    // Maximum value is digit ^ number of digits
    int maximumValue = static_cast<int>(std::pow(counterType, numberOfDigits));

    for (int i = 0; i < maximumValue; ++i) {
        counter.print(PRINT_OPTIONS::COUNTER_VALUE);
        ++counter;

        // When i reaches maximum value of a Digit Counter break into next line
        if ((i + 1) % lineBreakFrequency(counterType) == 0) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}


