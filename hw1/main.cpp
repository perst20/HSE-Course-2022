#include "biginteger.h"
#include <iostream>

int main() {
    std::cout << "Enter expression containing only numbers and +/- signs:" << std::endl;

    std::string raw_input;
    std::getline(std::cin, raw_input);

    std::string current;
    BigInteger number;

    for (auto c: raw_input) {
        if (std::isspace(c)) {
            continue;
        }
        if (std::isdigit(c)) {
            current.push_back(c);
        } else if (c == '-' || c == '+') {
            if (current == "-" || current == "+") {
                std::cerr << "Invalid expression";
                return 1;
            }
            number += current;

            current.erase();
            if (c == '-')
                current.push_back(c);
        } else {
            std::cerr << "String contains invalid characters";
            return 1;
        }
    }
    if (current == "-" || current == "+") {
        std::cerr << "Invalid expression";
        return 1;
    }
    number += current;

    std::cout << "Result equals: " << number;
}
