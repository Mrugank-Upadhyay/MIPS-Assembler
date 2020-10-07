#include "word.h"
#include <cmath>


// MUST ENSURE IT FITS IN THE RANGE OF -2^31 TO 2^32 - 1 for decimals
// NO GREATER THAN 0XFFFFFFFF FOR HEX
// AND UNSIGNED 32 BIT INTEGER FOR LABEL

Word::Word(std::vector<Token> tokenLine) {
    int64_t I;

    try {
        if (tokenLine.back().getKind() == Token::Kind::HEXINT) {
            std::stringstream ss;
            std::string max = "ffffffff";
            std::string hexint = tokenLine.back().getLexeme().substr(2);
            if (hexint.length() > max.length()) {
                throw WordFailure("ERROR: integer overflow");
            }
            I = tokenLine.back().toLong();
        }

        else if (tokenLine.back().getKind() == Token::Kind::INT) {

            int64_t tempInt = tokenLine.back().toLong();
            int64_t min = std::pow(-2, 31);
            int64_t max = std::pow(2, 32) - 1;

            if (tempInt < min || tempInt > max) {
                throw WordFailure("ERROR: integer overflow");
            }

            I = tempInt;
        }

        Instruction = I;
    }
    catch (WordFailure f) {
        throw f;
    }
}

int64_t Word::getInstruction() {
    return Instruction;
}


WordFailure::WordFailure(std::string message)
    : message{ std::move(message) } {}

const std::string& WordFailure::what() const {
    return message;
}
