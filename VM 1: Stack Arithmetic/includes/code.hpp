#ifndef CODE_HPP
#define CODE_HPP

#include "parser.hpp"
#include <string>
#include <fstream>

class Code
{
public:
    Code(std::ofstream file, std::string filename);
    void writeArithmetic(std::string command);
    void writePushPop(Command command, std::string segment, int index);
    void close();

private:
    void writeLine(std::string line);
    std::ofstream ofs;
    int count = 0;
    std::string name;
};

#endif