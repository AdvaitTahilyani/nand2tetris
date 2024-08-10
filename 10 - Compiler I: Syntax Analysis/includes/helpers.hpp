#ifndef HELPER_HPP
#define HELPER_HPP

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class Helper
{
public:
    static void processFile(fs::path inputPath);
};

#endif