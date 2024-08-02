#include "6 - Assembler/includes/helpers.hpp"
#include <string>

std::string binary(int num)
{
    int dividend = num;
    std::string output = "";
    int divisor = 16384;
    for (int i = 0; i < 15; i++)
    {
        output += std::to_string(dividend / divisor);
        dividend %= divisor;
        divisor /= 2;
    }
    return output;
}

bool digit(std::string str)
{
    char c = str[0];
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
    {
        return true;
    }
    return false;
}