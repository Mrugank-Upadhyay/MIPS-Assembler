#include "word.h"
#include <cmath>

Word::Word(std::vector<Token> tokenLine)
{
    int64_t I;

    try
    {
        if (tokenLine.back().getKind() == Token::Kind::HEXINT)
        {
            std::string max = "ffffffff";
            std::string hexint = tokenLine.back().getLexeme().substr(2);
            if (hexint.length() > max.length())
            {
                throw WordFailure("ERROR: integer overflow");
            }
            I = tokenLine.back().toLong();
        }

        else if (tokenLine.back().getKind() == Token::Kind::INT)
        {

            int64_t tempInt = tokenLine.back().toLong();
            int64_t min = std::pow(2, 31) * -1;
            int64_t max = std::pow(2, 32) - 1;

            if (tempInt < min || tempInt > max)
            {
                throw WordFailure("ERROR: integer overflow");
            }

            I = tempInt;
        }

        Instruction = I;
    }
    catch (WordFailure f)
    {
        throw f;
    }
}

int64_t Word::getInstruction()
{
    return Instruction;
}

WordFailure::WordFailure(std::string message)
    : message{std::move(message)} {}

const std::string &WordFailure::what() const
{
    return message;
}
