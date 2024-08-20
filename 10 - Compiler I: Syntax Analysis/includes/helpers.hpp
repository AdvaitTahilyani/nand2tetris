#ifndef HELPER_HPP
#define HELPER_HPP

#include "tokenizer.hpp"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class Helper
{
public:
    static void processFile(fs::path inputPath);
    static std::string openTag(std::string name);
    static std::string closeTag(std::string name);
};

#endif