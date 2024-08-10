#ifndef COMPILER_HPP
#define COMPILER_HPP

#include "tokenizer.hpp"
#include <fstream>

class Compiler
{
public:
    Compiler(std::string filename, std::ofstream ofs);
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