#include "parser.hpp"
#include "helpers.hpp"
#include "symbol_table.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

Parser::Parser(std::string filename)
{
    symbols = SymbolTable();
    std::ifstream ifs{filename};
    if (!ifs.is_open())
    {
        throw std::runtime_error("File could not be opened");
    }
    std::string line;
    while (std::getline(ifs, line))
    {
        line = trim(line, ' ');
        if (line == "" || line[0] == '\n' || line[0] == '/')
        {
            continue;
        }
        if (line[0] == '(')
        {
            std::string symbol = trim(trim(line, '('), ')');
            if (!digit(symbol))
            {
                if (!symbols.contains(symbol))
                {
                    symbols.addEntry(symbol, contents.size());
                }
                continue;
            }
        }
        contents.push_back(line);
    }
    translate();
}

bool Parser::hasMoreLines()
{
    return index < (contents.size() - 1);
}
void Parser::advance()
{
    index++;
    translate();
}
Instruction Parser::instructionType()
{
    char c = contents[index][0];
    if (c == '@')
    {
        return Instruction::A_INSTRUCTION;
    }
    if (c == '(')
    {
        return Instruction::L_INSTRUCTION;
    }
    return Instruction::C_INSTRUCTION;
}
std::string Parser::symbol()
{
    Instruction instruct = instructionType();
    if (instruct == Instruction::A_INSTRUCTION)
    {
        return trim(contents[index], '@');
    }
    return trim(trim(contents[index], '('), ')');
}
std::string Parser::dest()
{
    if (trim(contents[index], '=').size() == contents[index].size())
    {
        return "";
    }
    std::string str;
    for (char c : contents[index])
    {
        if (c == '=')
        {
            break;
        }
        if (c == ' ')
        {
            continue;
        }
        str += c;
    }
    return str;
}
std::string Parser::comp()
{
    std::string str = "";
    bool flag = false;
    if (dest() == "")
    {
        flag = true;
    }
    for (char c : contents[index])
    {

        if (c == ' ')
        {
            continue;
        }
        if (c == ';')
        {
            break;
        }
        if (flag)
        {
            str += c;
        }
        if (c == '=')
        {
            flag = true;
        }
    }
    return str;
}
std::string Parser::jump()
{
    std::string str;
    bool flag = false;
    for (char c : contents[index])
    {
        if (c == ' ')
        {
            continue;
        }
        if (flag)
        {
            str += c;
        }
        if (c == ';')
        {
            flag = true;
        }
    }
    return str;
}
std::string Parser::trim(std::string str, char comp)
{
    std::string final;
    for (char c : str)
    {
        if (c != comp)
        {
            final += c;
        }
    }
    return final;
}

void Parser::translate()
{
    if (instructionType() == Instruction::A_INSTRUCTION)
    {
        if (!digit(symbol()))
        {
            if (!symbols.contains(symbol()))
            {
                symbols.addEntry(symbol(), var_num);
                var_num++;
            }
            contents[index] = "@" + std::to_string(symbols.getAddress(symbol()));
        }
    }
}