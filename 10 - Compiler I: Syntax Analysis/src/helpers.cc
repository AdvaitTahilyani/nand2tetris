#include "helpers.hpp"
#include "tokenizer.hpp"
#include <iostream>
void Helper::processFile(fs::path inputPath)
{
    std::map<Keyword, std::string> keywordMap = {
        {CLASS, "class"}, {CONSTRUCTOR, "constructor"}, {FUNCTION, "function"}, {METHOD, "method"}, {FIELD, "field"}, {STATIC, "static"}, {VAR, "var"}, {INT, "int"}, {CHAR, "char"}, {BOOLEAN, "boolean"}, {VOID, "void"}, {TRUE, "true"}, {FALSE, "false"}, {KEY_NULL, "null"}, {THIS, "this"}, {LET, "let"}, {DO, "do"}, {IF, "if"}, {ELSE, "else"}, {WHILE, "while"}, {RETURN, "return"}};

    fs::path newFilePath = inputPath.parent_path() / (inputPath.stem().string() + ".xml");
    std::ofstream ofs{newFilePath};
    if (!ofs.is_open())
    {
        throw std::runtime_error("Could not create file");
    }
    Tokenizer tokenizer = Tokenizer(inputPath.string());
    ofs << "<tokens>" << std::endl;
    do
    {
        tokenizer.advance();
        Token token = tokenizer.tokenType();
        if (token == Token::IDENTIFIER)
        {
            ofs << openTag("identifier") << tokenizer.identifier() << closeTag("identifier") << std::endl;
        }
        else if (token == Token::INT_CONST)
        {
            ofs << openTag("integerConstant") << tokenizer.intVal() << closeTag("integerConstant") << std::endl;
        }
        else if (token == Token::KEYWORD)
        {
            ofs << openTag("keyword") << tokenizer.keyWord() << closeTag("keyword") << std::endl;
        }
        else if (token == Token::STRING_CONST)
        {
            ofs << openTag("stringConstant") << tokenizer.stringVal() << closeTag("stringConstant") << std::endl;
        }
        else
        {
            ofs << openTag("symbol") << tokenizer.symbol() << closeTag("symbol") << std::endl;
        }
    } while (tokenizer.hasMoreTokens());
    ofs << "</tokens>" << std::endl;
}

std::string Helper::openTag(std::string name)
{
    return "<" + name + ">";
}

std::string Helper::closeTag(std::string name)
{
    return "</" + name + ">";
}