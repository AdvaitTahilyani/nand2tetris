#include "helpers.hpp"
#include "tokenizer.hpp"

void Helper::processFile(fs::path inputPath)
{
    fs::path newFilePath = inputPath.parent_path() / (inputPath.stem().string() + ".xml");
    std::ofstream ofs{newFilePath};
    if (!ofs.is_open())
    {
        std::runtime_error("Could not create file");
    }
    Tokenizer tokenizer = Tokenizer(inputPath.string());
}