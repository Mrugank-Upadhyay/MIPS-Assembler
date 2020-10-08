#ifndef _LW_
#define _LW_

#include <vector>
#include <string>
#include <cmath>
#include "scanner.h"
#include "symbolTable.h"

class LW
{
    int Instruction;

public:
    LW(std::vector<Token> tokenLine);
    int getInstruction();
};

class LWFailure
{
    std::string message;

public:
    LWFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _LW_ */
