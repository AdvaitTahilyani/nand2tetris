#include "parser.hpp"
#include "code.hpp"
#include "helpers.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Incorrect format" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    Parser pars = Parser(filename + ".asm");
    std::ofstream ofs{filename + ".hack"};
    if (!ofs.is_open())
    {
        std::runtime_error("Could not create file");
    }
    while (pars.hasMoreLines())
    {
        if (pars.instructionType() == Instruction::C_INSTRUCTION)
        {
            ofs << "111" << Code::comp(pars.comp()) << Code::dest(pars.dest()) << Code::jump(pars.jump()) << std::endl;
        }
        else
        {
            ofs << "0" << binary(std::stoi(pars.symbol())) << std::endl;
        }
        pars.advance();
    }
    if (pars.instructionType() == Instruction::C_INSTRUCTION)
    {
        ofs << "111" << Code::comp(pars.comp()) << Code::dest(pars.dest()) << Code::jump(pars.jump()) << std::endl;
    }
    else
    {
        ofs << "0" << pars.symbol() << std::endl;
    }
    return 0;
}