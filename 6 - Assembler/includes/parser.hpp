#ifndef PARSER_HPP
#define PARSER_HPP

#include "symbol_table.hpp"
#include <string>
#include <vector>

enum Instruction
{
    A_INSTRUCTION,
    C_INSTRUCTION,
    L_INSTRUCTION,
};

class Parser
{
public:
    Parser(std::string filename);
    bool hasMoreLines();
    void advance();
    Instruction instructionType();
    std::string symbol();
    std::string dest();
    std::string comp();
    std::string jump();

private:
    std::string trim(std::string str, char comp);
    void translate();
    int var_num = 16;
    SymbolTable symbols;
    std::vector<std::string> contents;
    unsigned int index = 0;
};

#endif
