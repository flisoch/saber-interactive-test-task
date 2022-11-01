#include <iostream>
#include <vector>
#include <bitset>

#include "binaryPrinter.h"

int main()
{
    std::vector<int> testData = {2147483647, -2147483648, 0, 1, -1, 23745, -23745};

    for (auto num: testData) {
        printBinaryOf(num);
        std::cout << std::bitset<32>(num) << "\n\n";
    }
    
    return 0;
}