#include "compiler.hpp"
#include "tokenizer.hpp"
#include <fstream>
#include <stdexcept>

Compiler::Compiler(std::string filename, std::string output)
{
    tokenizer = Tokenizer(filename);
    std::ofstream ofs{output};
    if (!ofs.is_open())
    {
        std::runtime_error("Could not create file");
    }
}

void Compiler::compileClass()
{
    if (tokenizer.tokenType() != KEYWORD || tokenizer.keyWord() != CLASS)
    {
        std::runtime_error("File should start with a class");
    }
}

void Compiler::compileClassVarDec()
{
    // Implementation goes here
}

void Compiler::compileSubroutine()
{
    // Implementation goes here
}

void Compiler::compileParameterList()
{
    // Implementation goes here
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
