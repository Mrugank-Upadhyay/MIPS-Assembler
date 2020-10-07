#ifndef _INSTRUCTIONLINE_
#define _INSTRUCTIONLINE_

#include <vector>
#include <string>
#include "scanner.h"


class InstructionLine {
    std::vector<Token> tokenLine;
    int instructionStart;
    int PC;
public:
    InstructionLine(std::vector<Token> tokenLine, int instructionStart, int PC);
    std::vector<Token> getTokenLine();
    int getInstructionStart();
    int getPC();
};


#endif /* _INSTRUCTIONLINE_ */
