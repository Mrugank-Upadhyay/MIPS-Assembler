#include "add.h"

ADD::ADD(std::vector<Token> tokenLine)
{
    try
    {
        std::string reg1String = tokenLine[1].getLexeme();
        int D = std::stoi(reg1String.substr(1));
        std::string reg2String = tokenLine[3].getLexeme();
        int S = std::stoi(reg2String.substr(1));
        std::string TString = tokenLine[5].getLexeme();
        int T = std::stoi(TString.substr(1));

        if (0 > D || D > 31 || 0 > S || S > 31 || 0 > T || T > 31)
        {
            throw ADDFailure("ERROR: invalid register");
        }

        int DInstruction = D;
        DInstruction = DInstruction << 11;
        int SInstruction = S;
        SInstruction = SInstruction << 21;
        int TInstruction = T;
        TInstruction = TInstruction << 16;
        int functionCode = 1 << 5;

        Instruction = DInstruction | SInstruction | TInstruction | functionCode;
    }
    catch (const ADDFailure f)
    {
        throw f;
    }
}

int ADD::getInstruction()
{
    return Instruction;
}

ADDFailure::ADDFailure(std::string message)
    : message{std::move(message)} {}

const std::string &ADDFailure::what() const
{
    return message;
}
