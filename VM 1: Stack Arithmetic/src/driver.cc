#include "VM 1: Stack Arithmetic/includes/parser.hpp"
#include "VM 1: Stack Arithmetic/includes/code.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Incorrect format" << std::endl;
        return 1;
    }
    std::string filename = std::string(argv[1]);
    std::string extension;
    std::string path;
    std::string name;
    bool extensionFlag = true;
    bool nameFlag = false;
    bool pathFlag = false;
    for (int i = filename.size() - 1; i >= 0; i--)
    {
        if (filename[i] == '/')
        {
            pathFlag = true;
            nameFlag = false;
        }
        if (nameFlag)
        {
            name = filename[i] + name;
        }
        if (filename[i] == '.')
        {
            extensionFlag = false;
            nameFlag = true;
        }
        if (extensionFlag)
        {
            extension = filename[i] + extension;
        }
        if (pathFlag)
        {
            path = filename[i] + path;
        }
    }
    if (extension != "vm")
    {
        std::cout << "Incorrect extension" << std::endl;
        return 1;
    }
    Parser pars = Parser(filename);
    std::ofstream ofs{path + name + ".asm"};
    if (!ofs.is_open())
    {
        std::runtime_error("Could not create file");
    }
    Code codewriter = Code(std::move(ofs), name);
    while (pars.hasMoreLines())
    {
        if (pars.commandType() == Command::C_ARITHMETIC)
        {
            codewriter.writeArithmetic(pars.arg1());
        }
        else
        {
            codewriter.writePushPop(pars.commandType(), pars.arg1(), pars.arg2());
        }
        pars.advance();
    }
    if (pars.commandType() == Command::C_ARITHMETIC)
    {
        codewriter.writeArithmetic(pars.arg1());
    }
    else
    {
        codewriter.writePushPop(pars.commandType(), pars.arg1(), pars.arg2());
    }
    codewriter.close();
}