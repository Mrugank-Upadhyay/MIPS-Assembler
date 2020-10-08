#include "divu.h"

DIVU::DIVU(std::vector<Token> tokenLine)
{
    try
    {
        std::string reg1String = tokenLine[1].getLexeme();
        int S = std::stoi(reg1String.substr(1));
        std::string reg2String = tokenLine[3].getLexeme();
        int T = std::stoi(reg2String.substr(1));

        if (0 > S || S > 31 || 0 > T || T > 31)
        {
            throw DIVUFailure("ERROR: invalid register");
        }

        int SInstruction = S;
        SInstruction = SInstruction << 21;
        int TInstruction = T;
        TInstruction = TInstruction << 16;
        int functionCode = 1 << 4 | 1 << 3 | 1 << 1 | 1;

        Instruction = SInstruction | TInstruction | functionCode;
    }

    catch (const DIVUFailure f)
    {
        throw f;
    }
}

int DIVU::getInstruction()
{
    return Instruction;
}

DIVUFailure::DIVUFailure(std::string message)
    : message{std::move(message)} {}

const std::string &DIVUFailure::what() const
{
    return message;
}
