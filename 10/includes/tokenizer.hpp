#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <map>

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

class Tokenizer
{
public:
    Tokenizer(std::string filename);
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
    std::map<std::string, Keyword> keywords;
    bool stringCheck(std::string str);
    void trim(std::string &str, std::string comp);
    void processComments(std::string &str);
    unsigned int index = 0;
    unsigned int line_index = -1;
    unsigned int word_length = 1;
};

#endif
