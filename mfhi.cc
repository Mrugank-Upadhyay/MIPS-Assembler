#include "mfhi.h"

MFHI::MFHI(std::vector<Token> tokenLine)
{
    try
    {
        std::string reg1String = tokenLine[1].getLexeme();
        int D = std::stoi(reg1String.substr(1));

        if (0 > D || D > 31)
        {
            throw MFHIFailure("ERROR: invalid register");
        }

        int DInstruction = D;
        DInstruction = DInstruction << 11;
        int functionCode = 1 << 4;

        Instruction = DInstruction | functionCode;
    }
    catch (const MFHIFailure f)
    {
        throw f;
    }
}

int MFHI::getInstruction()
{
    return Instruction;
}

MFHIFailure::MFHIFailure(std::string message)
    : message{std::move(message)} {}

const std::string &MFHIFailure::what() const
{
    return message;
}
