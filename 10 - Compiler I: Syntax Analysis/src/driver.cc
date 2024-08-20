#include "tokenizer.hpp"
#include "compiler.hpp"
#include "helpers.hpp"
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
    fs::path newFilePath;
    Compiler compilationEngine;
    if (fs::is_directory(filename))
    {
        newFilePath = inputPath / (inputPath.filename().string() + ".xml");
        for (const auto &entry : fs::directory_iterator(filename))
        {
            if (entry.is_regular_file() && entry.path().extension() == ".jack")
            {
                fs::path newFilePath = inputPath.parent_path() / (inputPath.stem().string() + ".xml");
                compilationEngine = Compiler(entry.path(), newFilePath);
                compilationEngine.compileClass();
            }
        }
    }
    else
    {
        fs::path newFilePath = inputPath.parent_path() / (inputPath.stem().string() + ".xml");
        compilationEngine = Compiler(inputPath, newFilePath);
        compilationEngine.compileClass();
    }
}