#ifndef COMPILER_HPP
#define COMPILER_HPP

#include "tokenizer.hpp"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class Compiler
{
public:
    Compiler() = default;
    Compiler(std::string filename, std::string output);
    void compileClass();
    void compileClassVarDec();
    void compileSubroutine();
    void compileParameterList();
    void compileSubroutineBody();
    void compileVarDec();
    void compileStatements();
    void compileLet();
    void compileIf();
    void compileWhile();
    void compileDo();
    void compileReturn();
    void compileExpression();
    void compileTerm();
    int compileExpressionList();

private:
    Tokenizer tokenizer;
    std::ofstream ofs;
};

#endif