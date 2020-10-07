#include "instructionLine.h"

InstructionLine::InstructionLine(std::vector<Token> tokenLine, int instructionStart, int PC)
    : tokenLine{ tokenLine }, instructionStart{ instructionStart }, PC{ PC } {}


std::vector<Token> InstructionLine::getTokenLine() {
    return tokenLine;
}

int InstructionLine::getInstructionStart() {
    return instructionStart;
}

int InstructionLine::getPC() {
    return PC;
}