#include "tokenizer.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

Tokenizer::Tokenizer(std::string filename)
{
    std::ifstream ifs{filename};
    if (!ifs.is_open())
    {
        throw std::runtime_error("File could not be opened");
    }
    std::string line;
    while (std::getline(ifs, line))
    {
        processComments(line);
        trim(line, " ");
        trim(line, "\t");
        if (line == "" || line[0] == '\n')
        {
            continue;
        }
        contents.push_back(line);
    }
}

void Tokenizer::trim(std::string &str, std::string comp)
{
    while (str.find(comp) == 0)
    {
        str.erase(0, 1);
    }
    while (str.rfind(comp) == str.length() - 1)
    {
        str.erase(str.length() - 1, 1);
    }
}

void Tokenizer::processComments(std::string &str)
{
    unsigned int comInd = str.find("//");
    unsigned int comEnd = str.find("*/");
    if (comInd != std::string::npos)
    {
        str.erase(comInd, str.length() - comInd);
    }
    comInd = str.find("/*");
    while (comInd != std::string::npos)
    {
        if (comEnd == std::string::npos)
        {
            std::invalid_argument("Missing end of comment");
        }
        str.erase(comInd, (comEnd - comInd) + 2);
    }
}