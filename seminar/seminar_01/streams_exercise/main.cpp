#include <iostream>
#include "decimal-expansion.cpp"

int main() {
    int numer = 12, denom = 7;
    DecimalExpansion de(numer, denom);
    int precision = 10;

    for (int i = 0; i < precision; i++) {
        int nextDigit;
        de >> nextDigit;
        std::cout << "Next digit: " << nextDigit << std::endl;
    }
}