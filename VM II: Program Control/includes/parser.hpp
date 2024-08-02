#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

enum Command
{
    C_ARITHMETIC,
    C_PUSH,
    C_POP,
    C_LABEL,
    C_GOTO,
    C_IF,
    C_FUNCTION,
    C_RETURN,
    C_CALL,
};

class Parser
{
public:
    Parser(std::string filename);
    bool hasMoreLines();
    void advance();
    Command commandType();
    std::string arg1();
    int arg2();

private:
    std::vector<std::string> contents;
    std::string trim(std::string str, char comp);
    unsigned int index = 0;
};

#endif
