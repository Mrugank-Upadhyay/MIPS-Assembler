#include "sw.h"

SW::SW(std::vector<Token> tokenLine)
{
    try
    {
        std::string reg1String = tokenLine[5].getLexeme();
        int S = std::stoi(reg1String.substr(1));
        std::string reg2String = tokenLine[1].getLexeme();
        int T = std::stoi(reg2String.substr(1));
        std::string IString = tokenLine[3].getLexeme();
        int I;

        if (tokenLine[3].getKind() == Token::Kind::HEXINT)
        {
            std::string max = "ffff";
            std::string hexint = tokenLine[3].getLexeme().substr(2);
            if (hexint.length() > max.length())
            {
                throw SWFailure("ERROR: integer overflow");
            }

            I = tokenLine[3].toLong();
        }

        else if (tokenLine[3].getKind() == Token::Kind::INT)
        {
            int tempInt = tokenLine[3].toLong();
            int min = std::pow(2, 15) * -1;
            int max = std::pow(2, 15) - 1;

            if (tempInt < min || tempInt > max)
            {
                throw SWFailure("ERROR: integer overflow");
            }

            I = tempInt;
        }

        if (0 > S || S > 31 || 0 > T || T > 31)
        {
            throw SWFailure("ERROR: invalid register");
        }

        int SInstruction = S;
        SInstruction = SInstruction << 21;
        int TInstruction = T;
        TInstruction = TInstruction << 16;
        int opCode = 1 << 31 | 1 << 29 | 1 << 27 | 1 << 26;

        Instruction = opCode | SInstruction | TInstruction | (I & 0xffff);
    }
    catch (const SWFailure f)
    {
        throw f;
    }

    catch (const SymbolTableFailure f)
    {
        throw f;
    }
}

int SW::getInstruction()
{
    return Instruction;
}

SWFailure::SWFailure(std::string message)
    : message{std::move(message)} {}

const std::string &SWFailure::what() const
{
    return message;
}
