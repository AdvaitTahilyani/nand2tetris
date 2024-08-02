#include "Assembler/includes/code.hpp"

std::string Code::dest(std::string inp)
{
    if (inp == "")
        return "000";
    if (inp == "M")
        return "001";
    if (inp == "D")
        return "010";
    if (inp == "DM" || inp == "MD")
    {
        return "011";
    }
    if (inp == "A")
        return "100";
    if (inp == "AM")
        return "101";
    if (inp == "AD")
        return "110";
    return "111";
}
std::string Code::comp(std::string inp)
{
    if (inp == "0")
        return "0101010";
    if (inp == "1")
        return "0111111";
    if (inp == "-1")
        return "0111010";
    if (inp == "D")
        return "0001100";
    if (inp == "A")
        return "0110000";
    if (inp == "!D")
        return "0001101";
    if (inp == "!A")
        return "0110001";
    if (inp == "-D")
        return "0001111";
    if (inp == "-A")
        return "0110011";
    if (inp == "D+1")
        return "0011111";
    if (inp == "A+1")
        return "0110111";
    if (inp == "D-1")
        return "0001110";
    if (inp == "A-1")
        return "0110010";
    if (inp == "D+A")
        return "0000010";
    if (inp == "D-A")
        return "0010011";
    if (inp == "A-D")
        return "0000111";
    if (inp == "D&A")
        return "0000000";
    if (inp == "D|A")
        return "0010101";
    if (inp == "M")
        return "1110000";
    if (inp == "!M")
        return "1110001";
    if (inp == "-M")
        return "1110011";
    if (inp == "M+1")
        return "1110111";
    if (inp == "M-1")
        return "1110010";
    if (inp == "D+M")
        return "1000010";
    if (inp == "D-M")
        return "1010011";
    if (inp == "M-D")
        return "1000111";
    if (inp == "D&M")
        return "1000000";
    return "1010101";
}
std::string Code::jump(std::string inp)
{
    if (inp == "")
        return "000";
    if (inp == "JGT")
        return "001";
    if (inp == "JEQ")
        return "010";
    if (inp == "JGE")
        return "011";
    if (inp == "JLT")
        return "100";
    if (inp == "JNE")
        return "101";
    if (inp == "JLE")
        return "110";
    return "111";
}