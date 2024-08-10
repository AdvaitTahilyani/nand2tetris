#include "helpers.hpp"

void Helper::processFile(fs::path inputPath)
{
    fs::path newFilePath = inputPath / (inputPath.stem().string() + ".xml");
}