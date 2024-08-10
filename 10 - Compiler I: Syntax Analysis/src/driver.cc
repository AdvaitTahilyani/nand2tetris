#include "tokenizer.hpp"
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
        newFilePath = inputPath / (inputPath.filename().string() + ".xml");
        path = filename;
    }
    else
    {
        path = inputPath.parent_path();
        newFilePath = inputPath.parent_path() / (inputPath.stem().string() + ".xml");
        for (const auto &entry : fs::directory_iterator(path))
        {
            if (entry.is_regular_file() && entry.path().extension() == ".jack")
            {
            }
        }
    }
    std::ofstream ofs{newFilePath};
    if (!ofs.is_open())
    {
        std::runtime_error("Could not create file");
    }
}