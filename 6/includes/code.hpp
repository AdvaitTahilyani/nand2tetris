#ifndef CODE_HPP
#define CODE_HPP

#include <string>

class Code
{
public:
    static std::string dest(std::string inp);
    static std::string comp(std::string inp);
    static std::string jump(std::string inp);
};

#endif