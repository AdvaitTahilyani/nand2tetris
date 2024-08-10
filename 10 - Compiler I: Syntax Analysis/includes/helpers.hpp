#ifndef HELPER_HPP
#define HELPER_HPP

#include "tokenizer.hpp"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class Helper
{
public:
    void processFile(fs::path inputPath);
};

#endif