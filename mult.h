#ifndef _MULT_
#define _MULT_

#include <vector>
#include <string>
#include "scanner.h"

class MULT
{
    int Instruction;

public:
    MULT(std::vector<Token> tokenLine);
    int getInstruction();
};

class MULTFailure
{
    std::string message;

public:
    MULTFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _MULT_ */
