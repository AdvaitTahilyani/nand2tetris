#include "tokenizer.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cctype>

Tokenizer::Tokenizer(std::string filename)
{
    keywords = {
        {"class", CLASS}, {"constructor", CONSTRUCTOR}, {"function", FUNCTION}, {"method", METHOD}, {"field", FIELD}, {"static", STATIC}, {"var", VAR}, {"int", INT}, {"char", CHAR}, {"boolean", BOOLEAN}, {"void", VOID}, {"true", TRUE}, {"false", FALSE}, {"null", KEY_NULL}, {"this", THIS}, {"let", LET}, {"do", DO}, {"if", IF}, {"else", ELSE}, {"while", WHILE}, {"return", RETURN}};
    symbols = {
        '{', '}', '(', ')', '[', ']', '.', ',', ';', '+', '-', '*', '/',
        '&', '|', '<', '>', '=', '~'};
    symbolsMap = {{'<', "&lt"}, {'>', "&gt"}, {'"', "&quot"}, {'&', "&amp"}};
    std::ifstream ifs{filename};
    if (!ifs.is_open())
    {
        throw std::runtime_error("File could not be opened");
    }
    std::string line;
    while (std::getline(ifs, line))
    {
        processComments(line);
        line = trim(line, " ");
        line = trim(line, "\t");
        if (line == "" || line[0] == '\n')
        {
            continue;
        }
        contents.push_back(line);
    }
}

bool Tokenizer::hasMoreTokens()
{
    return !(index == contents.size() - 1 && line_index == contents[index].size() - 1);
}

void Tokenizer::advance()
{
    if (line_index + word_length >= contents[index].size())
    {
        line_index = 0;
        index++;
    }
    else
    {
        line_index = line_index + word_length;
        word_length = 1;
        if (contents[index][line_index] == ' ')
        {
            advance();
        }
    }
}

Token Tokenizer::tokenType()
{
    if (isdigit(contents[index][line_index]))
    {
        for (unsigned int i = line_index; i < contents[index].size(); i++)
        {
            if (!isdigit(contents[index][i]))
            {
                word_length = i - line_index;
                return Token::INT_CONST;
            }
        }
    }
    if (contents[index][line_index] == '"')
    {
        word_length = contents[index].substr(line_index + 1).find('"') + 1;
        return Token::STRING_CONST;
    }
    if (stringCheck(contents[index].substr(line_index)))
    {
        return Token::KEYWORD;
    }
    if (symbolCheck(contents[index][line_index]))
    {
        return Token::SYMBOL;
    }
    for (unsigned int i = line_index; i < contents[index].size(); i++)
    {
        if (!(isalnum(contents[index][i]) || contents[index][i] == '_'))
        {
            word_length = i - line_index;
            break;
        }
    }
    return Token::IDENTIFIER;
}

Keyword Tokenizer::keyWord()
{
    return keywords[contents[index].substr(line_index, word_length)];
}

std::string Tokenizer::symbol()
{
    char c = contents[index][line_index];
    if (symbolsMap.find(c) != symbolsMap.end())
    {
        return symbolsMap[c];
    }
    return std::string(1, c);
}

std::string Tokenizer::identifier()
{
    return contents[index].substr(line_index, word_length);
}

int Tokenizer::intVal()
{
    return stoi(contents[index].substr(line_index, word_length));
}

std::string Tokenizer::stringVal()
{
    return trim(contents[index].substr(line_index, word_length), "\"");
}
std::string Tokenizer::trim(std::string str, std::string comp)
{
    if (str == "")
    {
        return str;
    }
    while (str.find(comp) == 0)
    {
        str.erase(0, 1);
    }
    while (str.rfind(comp) == str.length() - 1 && str != "")
    {
        str.erase(str.length() - 1);
    }
    return str;
}
void Tokenizer::processComments(std::string &str)
{
    if (str == "")
    {
        return;
    }
    size_t comInd = str.find("//");
    size_t comEnd = str.find("*/");
    if (comInd != std::string::npos)
    {
        str.erase(comInd);
    }
    comInd = str.find("/*");
    while (comInd != std::string::npos)
    {
        if (comEnd == std::string::npos)
        {
            std::invalid_argument("Missing end of comment");
        }
        str.erase(comInd, (comEnd - comInd) + 2);
        comInd = str.find("/*");
        comEnd = str.find("*/");
    }
}

bool Tokenizer::stringCheck(std::string str)
{
    for (auto const &[key, value] : keywords)
    {
        if (str.find(key) == 0)
        {
            word_length = key.length();
            return true;
        }
    }
    return false;
}

bool Tokenizer::symbolCheck(char c)
{
    for (char a : symbols)
    {
        if (c == a)
        {
            word_length = 1;
            return true;
        }
    }
    return false;
}