#include "mflo.h"

MFLO::MFLO(std::vector<Token> tokenLine)
{
    try
    {
        std::string reg1String = tokenLine[1].getLexeme();
        int D = std::stoi(reg1String.substr(1));

        if (0 > D || D > 31)
        {
            throw MFLOFailure("ERROR: invalid register");
        }

        int DInstruction = D;
        DInstruction = DInstruction << 11;
        int functionCode = 1 << 4 | 1 << 1;

        Instruction = DInstruction | functionCode;
    }
    catch (const MFLOFailure f)
    {
        throw f;
    }
}

int MFLO::getInstruction()
{
    return Instruction;
}

MFLOFailure::MFLOFailure(std::string message)
    : message{std::move(message)} {}

const std::string &MFLOFailure::what() const
{
    return message;
}
