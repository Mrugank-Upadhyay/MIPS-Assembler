#include "beq.h"

BEQ::BEQ(std::vector<Token> tokenLine, int PC, SymbolTable table)
{
    try
    {
        std::string reg1String = tokenLine[1].getLexeme();
        int S = std::stoi(reg1String.substr(1));
        std::string reg2String = tokenLine[3].getLexeme();
        int T = std::stoi(reg2String.substr(1));
        std::string IString = tokenLine[5].getLexeme();
        int I;

        if (tokenLine[5].getKind() == Token::Kind::HEXINT)
        {
            std::string max = "ffff";
            std::string hexint = tokenLine[5].getLexeme().substr(2);
            if (hexint.length() > max.length())
            {
                throw BEQFailure("ERROR: integer overflow");
            }

            I = tokenLine[5].toLong();
        }

        else if (tokenLine[5].getKind() == Token::Kind::INT)
        {
            int tempInt = tokenLine.back().toLong();
            int min = std::pow(2, 15) * -1;
            int max = std::pow(2, 15) - 1;

            if (tempInt < min || tempInt > max)
            {
                throw BEQFailure("ERROR: integer overflow");
            }

            I = tempInt;
        }
        else
        {
            int labelValue = table.find(tokenLine[5].getLexeme());
            I = (labelValue - PC - 4) / 4;
        }

        if (0 > S || S > 31 || 0 > T || T > 31)
        {
            throw BEQFailure("ERROR: invalid register");
        }

        int SInstruction = S;
        SInstruction = SInstruction << 21;
        int TInstruction = T;
        TInstruction = TInstruction << 16;
        int opCode = 1 << 28;

        Instruction = opCode | SInstruction | TInstruction | (I & 0xffff);
    }
    catch (const BEQFailure f)
    {
        throw f;
    }

    catch (const SymbolTableFailure f)
    {
        throw f;
    }
}

int BEQ::getInstruction()
{
    return Instruction;
}

BEQFailure::BEQFailure(std::string message)
    : message{std::move(message)} {}

const std::string &BEQFailure::what() const
{
    return message;
}
