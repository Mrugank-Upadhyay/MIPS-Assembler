#include "instructions.h"

Instructions::Instructions(std::vector<Token> tokenLine, int PC) {
    if (tokenLine[0].getKind() == Token::Kind::WORD) {
        Word word{ tokenLine };
        binaryInstruction = word.getInstruction();
    }
    else if (tokenLine[0].getKind() == Token::Kind::ID) {
        if (tokenLine[0].getLexeme() == "add") {

        }
    }
}

int64_t Instructions::getInstruction() {
    return binaryInstruction;
}
