#include "jalr.h"

JALR::JALR(std::vector<Token> tokenLine)
{
    int instruction;
    std::string regString = tokenLine.back().getLexeme();
    int reg = std::stoi(regString.substr(1));

    if (0 > reg || reg > 31)
    {
        throw JALRFailure("ERROR: invalid register");
    }

    instruction = reg;
    instruction = instruction << 21;
    int functionCode = 1 << 3 | 1;

    Instruction = instruction | functionCode;
}

int JALR::getInstruction()
{
    return Instruction;
}

JALRFailure::JALRFailure(std::string message)
    : message{std::move(message)} {}

const std::string &JALRFailure::what() const
{
    return message;
}
