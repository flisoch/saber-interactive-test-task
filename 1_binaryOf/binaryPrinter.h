#include <iostream>

const int BITS_COUNT = 31;

void printBinaryOf(int number)
{   
    unsigned int mask = 1 << BITS_COUNT;     // двоичное число вида 1000...0 с 31 нулём

    while(mask) {

        bool current_msb = number & mask; //если msb(старший бит) number не совпадает по разряду с msb маски, то результат всегда 0
        std::cout << current_msb;
        
        mask = mask >> 1;   //убираем последний разряд маски
    }
    std::cout << "\n";
}