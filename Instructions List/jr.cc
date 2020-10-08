#include "jr.h"

JR::JR(std::vector<Token> tokenLine)
{
    int instruction;
    std::string regString = tokenLine.back().getLexeme();
    int reg = std::stoi(regString.substr(1));

    if (0 > reg || reg > 31)
    {
        throw JRFailure("ERROR: invalid register");
    }

    instruction = reg;
    instruction = instruction << 21;
    int functionCode = 1 << 3;

    Instruction = instruction | functionCode;
}

int JR::getInstruction()
{
    return Instruction;
}

JRFailure::JRFailure(std::string message)
    : message{std::move(message)} {}

const std::string &JRFailure::what() const
{
    return message;
}
