#ifndef _BNE_
#define _BNE_

#include <vector>
#include <string>
#include <cmath>
#include "scanner.h"

class BNE
{
    int Instruction;

public:
    BNE(std::vector<Token> tokenLine);
    int getInstruction();
};

class BNEFailure
{
    std::string message;

public:
    BNEFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _BNE_ */
