#include "VM 1: Stack Arithmetic/includes/parser.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

Parser::Parser(std::string filename)
{
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
        contents.push_back(line);
    }
}

bool Parser::hasMoreLines()
{
    return index < (contents.size() - 1);
}
void Parser::advance()
{
    index++;
}
Command Parser::commandType()
{
    std::string word;
    for (char c : contents[index])
    {
        if (c == ' ')
        {
            break;
        }
        word += c;
    }
    if (word == "push")
    {
        return Command::C_PUSH;
    }
    if (word == "pop")
    {
        return Command::C_POP;
    }
    if (word == "add" || word == "sub" || word == "neg" || word == "eq" || word == "gt" || word == "lt" || word == "and" || word == "or" || word == "not")
    {
        return Command::C_ARITHMETIC;
    }
    return Command::C_LABEL;
}
std::string Parser::arg1()
{
    std::string word;
    bool flag = false;
    if (commandType() == Command::C_ARITHMETIC)
    {
        return contents[index];
    }
    for (char c : contents[index])
    {
        if (flag)
        {
            if (c == ' ')
            {
                break;
            }
            word += c;
        }
        if (c == ' ')
        {
            flag = true;
        }
    }
    return word;
}

int Parser::arg2()
{
    std::string word;
    int count = 0;
    for (char c : contents[index])
    {
        if (c == ' ')
        {
            count++;
        }
        if (count == 2)
        {
            word += c;
        }
    }
    return std::stoi(word);
}
std::string Parser::trim(std::string str, char comp)
{
    std::string final;
    std::string trimmed;
    bool flag = false;
    for (char c : str)
    {
        if (c != comp || flag)
        {
            flag = true;
            final += c;
        }
    }
    for (int i = final.size() - 1; i >= 0; i--)
    {
        if (final[i] != comp || flag)
        {
            flag = true;
            trimmed = final[i] + trimmed;
        }
    }
    return trimmed;
}