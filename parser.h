#ifndef _PARSER_
#define _PARSER_

#include "scanner.h"
#include <string>
#include <vector>
#include "symbolTable.h"

class Parser
{
    int instructionStart = 0;
    bool skip;
    bool contains_label = false;
    void ParsingRules(std::vector<Token> tokenLine, int count);

public:
    Parser(std::vector<Token> tokenLine, SymbolTable &symbolTable, int PC);
    int getInstructionStart();
    bool getSkip();
    bool getContainsLabel();
};

class ParsingFailure
{
    std::string message;

public:
    ParsingFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _PARSER_ */
