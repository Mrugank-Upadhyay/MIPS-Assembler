#include "lis.h"

LIS::LIS(std::vector<Token> tokenLine)
{
    try
    {
        std::string reg1String = tokenLine[1].getLexeme();
        int D = std::stoi(reg1String.substr(1));

        if (0 > D || D > 31)
        {
            throw LISFailure("ERROR: invalid register");
        }

        int DInstruction = D;
        DInstruction = DInstruction << 11;
        int functionCode = 1 << 4 | 1 << 2;

        Instruction = DInstruction | functionCode;
    }
    catch (const LISFailure f)
    {
        throw f;
    }
}

int LIS::getInstruction()
{
    return Instruction;
}

LISFailure::LISFailure(std::string message)
    : message{std::move(message)} {}

const std::string &LISFailure::what() const
{
    return message;
}
