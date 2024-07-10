#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

enum Token
{
    KEYWORD,
    SYMBOL,
    IDENTIFIER,
    INT_CONST,
    STRING_CONST,
};

enum Keyword
{
    CLASS,
    METHOD,
    FUNCTION,
    CONSTRUCTOR,
    INT,
    BOOLEAN,
    CHAR,
    VOID,
    VAR,
    STATIC,
    FIELD,
    LET,
    DO,
    IF,
    ELSE,
    WHILE,
    RETURN,
    TRUE,
    FALSE,
    KEY_NULL,
    THIS,
};

class Parser
{
public:
    Parser(std::string filename);
    bool hasMoreTokens();
    void advance();
    Token tokenType();
    Keyword keyWord();
    char symbol();
    std::string identifier();
    int intVal();
    std::string stringVal();

private:
    std::vector<std::string> contents;
    std::string trim(std::string str, char comp);
    unsigned int index = -1;
    unsigned int line_index = 0;
};

#endif
