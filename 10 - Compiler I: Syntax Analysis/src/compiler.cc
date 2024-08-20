#include "compiler.hpp"
#include "tokenizer.hpp"
#include "helpers.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

Compiler::Compiler(std::string filename, std::string output)
{
    tokenizer = Tokenizer(filename);
    ofs.open(output);
    if (!ofs.is_open())
    {
        throw std::runtime_error("Could not create file");
    }
}

void Compiler::compileClass()
{
    tokenizer.advance();
    if (tokenizer.tokenType() != KEYWORD || tokenizer.keyWord() != "class")
    {
        tokenizer.error("File should start with a class");
    }
    ofs << Helper::openTag("class") << std::endl;
    compileKeyword();
    compileIdentifier();
    compileSymbol();
    while (tokenizer.tokenType() == KEYWORD && (tokenizer.keyWord() == "static" || tokenizer.keyWord() == "field"))
    {
        compileClassVarDec();
    }
    while (tokenizer.tokenType() == KEYWORD && (tokenizer.keyWord() == "function" || tokenizer.keyWord() == "method" || tokenizer.keyWord() == "constructor"))
    {
        compileSubroutine();
    }
    ofs << Helper::closeTag("class") << std::endl;
}

void Compiler::compileClassVarDec()
{
    ofs << Helper::openTag("classVarDec") << std::endl;
    compileKeyword();
    compileType();
    compileIdentifier();
    while (tokenizer.tokenType() == SYMBOL && tokenizer.symbol() != ";")
    {
        compileSymbol();
        compileIdentifier();
    }
    compileSymbol();
    ofs << Helper::closeTag("classVarDec") << std::endl;
}

void Compiler::compileSubroutine()
{
    ofs << Helper::openTag("subroutine") << std::endl;
    compileKeyword();
    if (tokenizer.tokenType() == KEYWORD && tokenizer.keyWord() == "void")
    {
        compileKeyword();
    }
    else
    {
        compileType();
    }
    compileIdentifier();
    compileSymbol();
    compileParameterList();
    compileSymbol();
    compileSubroutineBody();
    ofs << Helper::closeTag("subroutine") << std::endl;
}

void Compiler::compileParameterList()
{
    ofs << Helper::openTag("parameterList") << std::endl;
    while (tokenizer.tokenType() != SYMBOL || tokenizer.symbol() != ")")
    {
        if (tokenizer.tokenType() == SYMBOL)
        {
            compileSymbol();
        }
        compileType();
        compileIdentifier();
    }
    ofs << Helper::closeTag("parameterList") << std::endl;
}

void Compiler::compileSubroutineBody()
{
    // Implementation goes here
}

void Compiler::compileVarDec()
{
    // Implementation goes here
}

void Compiler::compileStatements()
{
    // Implementation goes here
}

void Compiler::compileLet()
{
    // Implementation goes here
}

void Compiler::compileIf()
{
    // Implementation goes here
}

void Compiler::compileWhile()
{
    // Implementation goes here
}

void Compiler::compileDo()
{
    // Implementation goes here
}

void Compiler::compileReturn()
{
    // Implementation goes here
}

void Compiler::compileExpression()
{
    // Implementation goes here
}

void Compiler::compileTerm()
{
    // Implementation goes here
}

int Compiler::compileExpressionList()
{
    // Implementation goes here
    return 0; // Placeholder return
}

void Compiler::compileKeyword()
{
    if (tokenizer.tokenType() != KEYWORD)
    {
        tokenizer.error("Expected a keyword");
    }
    ofs << Helper::openTag("keyword") << tokenizer.keyWord() << Helper::closeTag("keyword") << std::endl;
    tokenizer.advance();
}

void Compiler::compileIdentifier()
{
    if (tokenizer.tokenType() != IDENTIFIER)
    {
        tokenizer.error("Expected an identifier");
    }
    ofs << Helper::openTag("identifier") << tokenizer.identifier() << Helper::closeTag("identifier") << std::endl;
    tokenizer.advance();
}

void Compiler::compileSymbol()
{
    if (tokenizer.tokenType() != SYMBOL)
    {
        tokenizer.error("Expected a symbol");
    }
    ofs << Helper::openTag("symbol") << tokenizer.symbol() << Helper::closeTag("symbol") << std::endl;
    tokenizer.advance();
}

void Compiler::compileType()
{
    if (tokenizer.tokenType() == KEYWORD && (tokenizer.keyWord() == "boolean" || tokenizer.keyWord() == "int" || tokenizer.keyWord() == "char"))
    {
        compileKeyword();
    }
    else if (tokenizer.tokenType() == IDENTIFIER)
    {
        compileIdentifier();
    }
    else
    {
        tokenizer.error("Expected data type or class name");
    }
}
