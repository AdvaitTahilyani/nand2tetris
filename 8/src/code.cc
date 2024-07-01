#include "code.hpp"
#include <iostream>

Code::Code(std::ofstream file)
{
    ofs = std::move(file);
    writeLine("@256");
    writeLine("D=A");
    writeLine("@SP");
    writeLine("M=D");
    writeCall("Sys.init", 0);
}
void Code::setFileName(std::string filename)
{
    name = filename;
}
void Code::writeArithmetic(std::string command)
{
    if (command == "neg" || command == "not")
    {
        writePushPop(Command::C_POP, "R", 14);
        writeLine("@R14");
        if (command == "neg")
        {
            writeLine("M=-M");
        }
        else
        {
            writeLine("M=!M");
        }
        writePushPop(Command::C_PUSH, "R", 14);
    }
    else
    {
        writePushPop(Command::C_POP, "R", 14);
        writePushPop(Command::C_POP, "R", 15);
        writeLine("@R14");
        writeLine("D=M");
        writeLine("@R15");
        if (command == "add")
        {
            writeLine("M=D+M");
        }
        else if (command == "sub")
        {
            writeLine("M=M-D");
        }
        else if (command == "and")
        {
            writeLine("M=D&M");
        }
        else if (command == "or")
        {
            writeLine("M=D|M");
        }
        else
        {
            std::string jump;
            if (command == "eq")
            {
                jump = "JEQ";
            }
            else if (command == "gt")
            {
                jump = "JGT";
            }
            else
            {
                jump = "JLT";
            }
            writeLine("D=M-D");
            writeLine("@TRUE" + std::to_string(count));
            writeLine("D;" + jump);
            writeLine("@R15");
            writeLine("M=0");
            writeLine("@LEND" + std::to_string(count));
            writeLine("0;JMP");
            writeLine("(TRUE" + std::to_string(count) + ")");
            writeLine("@R15");
            writeLine("M=-1");
            writeLine("(LEND" + std::to_string(count) + ")");
            count++;
        }
        writePushPop(Command::C_PUSH, "R", 15);
    }
}
void Code::writePushPop(Command command, std::string segment, int index)
{

    std::string var;
    if (segment == "local")
    {
        var = "LCL";
    }
    else if (segment == "argument")
    {
        var = "ARG";
    }
    else if (segment == "this")
    {
        var = "THIS";
    }
    else if (segment == "that")
    {
        var = "THAT";
    }
    if (command == Command::C_POP)
    {
        writeLine("@SP");
        writeLine("M=M-1");
        if (segment == "temp")
        {
            writeLine("A=M");
            writeLine("D=M");
            writeLine("@" + std::to_string((5 + index)));
        }
        else if (segment == "R")
        {
            writeLine("@SP");
            writeLine("A=M");
            writeLine("D=M");
            writeLine("@R" + std::to_string(index));
        }
        else if (segment == "static")
        {
            writeLine("@SP");
            writeLine("A=M");
            writeLine("D=M");
            writeLine("@" + name + std::to_string(index));
        }
        else
        {
            writeLine("@" + var);
            writeLine("D=M");
            writeLine("@" + std::to_string(index));
            writeLine("D=D+A");
            writeLine("@R13");
            writeLine("M=D");
            writeLine("@SP");
            writeLine("A=M");
            writeLine("D=M");
            writeLine("@R13");
            writeLine("A=M");
        }
        writeLine("M=D");
    }
    else
    {
        if (segment == "temp")
        {
            writeLine("@" + std::to_string((5 + index)));
            writeLine("D=M");
        }
        else if (segment == "R")
        {
            writeLine("@R" + std::to_string(index));
            writeLine("D=M");
        }
        else if (segment == "constant")
        {
            writeLine("@" + std::to_string(index));
            writeLine("D=A");
        }
        else if (segment == "static")
        {
            writeLine("@" + name + std::to_string(index));
            writeLine("D=M");
        }
        else
        {
            writeLine("@" + var);
            writeLine("D=M");
            writeLine("@" + std::to_string(index));
            writeLine("D=D+A");
            writeLine("A=D");
            writeLine("D=M");
        }
        push();
    }
}
void Code::writeLabel(std::string label)
{
    // Add Function mapping
    writeLine("(" + function + "$" + label + ")");
}
void Code::writeGoto(std::string label)
{
    writeLine("@" + function + "$" + label);
    writeLine("0;JMP");
}
void Code::writeIf(std::string label)
{
    writePushPop(Command::C_POP, "R", 14);
    writeLine("@R14");
    writeLine("D=M");
    writeLine("@" + function + "$" + label);
    writeLine("D;JNE");
}
void Code::writeFunction(std::string functionName, int nVars)
{
    retcount = 0;
    function = functionName;
    writeLine("(" + function + ")");
    for (int i = 0; i < nVars; i++)
    {
        writePushPop(Command::C_PUSH, "constant", 0);
    }
}
void Code::writeCall(std::string functionName, int nArgs)
{
    writeLine("@" + function + "$ret." + std::to_string(retcount));
    writeLine("D=A");
    push();
    writeLine("@LCL");
    writeLine("D=M");
    push();
    writeLine("@ARG");
    writeLine("D=M");
    push();
    writeLine("@THIS");
    writeLine("D=M");
    push();
    writeLine("@THAT");
    writeLine("D=M");
    push();
    writeLine("@SP");
    writeLine("D=M");
    writeLine("@" + std::to_string(5 + nArgs));
    writeLine("D=D-A");
    writeLine("@ARG");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("D=M");
    writeLine("@LCL");
    writeLine("M=D");
    writeLine("@" + functionName);
    writeLine("0;JMP");
    writeLine("(" + function + "$ret." + std::to_string(retcount) + ")");
    retcount++;
}
void Code::writeReturn()
{
    writeLine("@LCL");
    writeLine("D=M");
    writeLine("@R14");
    writeLine("M=D");
    restore("R15", 5);
    writePushPop(Command::C_POP, "argument", 0);
    writeLine("@ARG");
    writeLine("D=M+1");
    writeLine("@SP");
    writeLine("M=D");
    restore("THAT", 1);
    restore("THIS", 2);
    restore("ARG", 3);
    restore("LCL", 4);
    writeLine("@R15");
    writeLine("A=M");
    writeLine("0;JMP");
}
void Code::close()
{
    // writeLine("(END)");
    // writeLine("@END");
    // writeLine("0;JMP");
    ofs.close();
}
void Code::writeLine(std::string line)
{
    ofs << line << std::endl;
}
void Code::push()
{
    writeLine("@SP");
    writeLine("A=M");
    writeLine("M=D");
    writeLine("@SP");
    writeLine("M=M+1");
}
void Code::restore(std::string var, int num)
{
    writeLine("@R14");
    writeLine("D=M");
    writeLine("@" + std::to_string(num));
    writeLine("D=D-A");
    writeLine("A=D");
    writeLine("D=M");
    writeLine("@" + var);
    writeLine("M=D");
}