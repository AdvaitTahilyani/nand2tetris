#include "parser.hpp"
#include "code.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Incorrect format" << std::endl;
        return 1;
    }
    std::string filename = std::string(argv[1]);
    fs::path inputPath(filename);
    std::string path;
    fs::path newFilePath;
    if (fs::is_directory(filename))
    {
        newFilePath = inputPath / (inputPath.filename().string() + ".asm");
        path = filename;
    }
    else
    {
        path = inputPath.parent_path();
        newFilePath = inputPath.parent_path() / (inputPath.stem().string() + ".asm");
    }
    std::ofstream ofs{newFilePath};
    if (!ofs.is_open())
    {
        std::runtime_error("Could not create file");
    }
    Code codewriter = Code(std::move(ofs));
    for (const auto &entry : fs::directory_iterator(path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".vm")
        {
            std::string name = entry.path().stem();
            codewriter.setFileName(name);
            Parser pars = Parser(entry.path().string());
            while (pars.hasMoreLines())
            {
                Command com = pars.commandType();
                if (com == Command::C_ARITHMETIC)
                {
                    codewriter.writeArithmetic(pars.arg1());
                }
                else if (com == Command::C_POP || com == Command::C_PUSH)
                {
                    codewriter.writePushPop(com, pars.arg1(), pars.arg2());
                }
                else if (com == Command::C_LABEL)
                {
                    codewriter.writeLabel(pars.arg1());
                }
                else if (com == Command::C_GOTO)
                {
                    codewriter.writeGoto(pars.arg1());
                }
                else if (com == Command::C_IF)
                {
                    codewriter.writeIf(pars.arg1());
                }
                else if (com == Command::C_FUNCTION)
                {
                    codewriter.writeFunction(pars.arg1(), pars.arg2());
                }
                else if (com == Command::C_CALL)
                {
                    codewriter.writeCall(pars.arg1(), pars.arg2());
                }
                else
                {
                    codewriter.writeReturn();
                }
                pars.advance();
            }
        }
    }
    codewriter.close();
}