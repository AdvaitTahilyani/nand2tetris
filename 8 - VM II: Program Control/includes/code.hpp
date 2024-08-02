#ifndef CODE_HPP
#define CODE_HPP

#include "parser.hpp"
#include <string>
#include <fstream>

class Code
{
public:
    Code(std::ofstream file);
    void setFileName(std::string filename);
    void writeArithmetic(std::string command);
    void writePushPop(Command command, std::string segment, int index);
    void writeLabel(std::string label);
    void writeGoto(std::string label);
    void writeIf(std::string label);
    void writeFunction(std::string functionName, int nVars);
    void writeCall(std::string functionName, int nArgs);
    void writeReturn();
    void close();

private:
    void push();
    void writeLine(std::string line);
    void restore(std::string var, int num);
    std::ofstream ofs;
    int count = 0;
    int retcount = 0;
    std::string name;
    std::string function;
};

#endif