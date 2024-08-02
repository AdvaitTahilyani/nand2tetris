#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <map>
#include <string>

class SymbolTable
{
public:
    SymbolTable();
    void addEntry(std::string symbol, int address);
    bool contains(std::string symbol);
    int getAddress(std::string symbol);

private:
    std::map<std::string, int> symbols;
};

#endif