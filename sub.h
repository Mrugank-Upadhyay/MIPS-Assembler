#ifndef _SUB_
#define _SUB_

#include <vector>
#include <string>
#include "scanner.h"

class SUB
{
    int Instruction;

public:
    SUB(std::vector<Token> tokenLine);
    int getInstruction();
};

class SUBFailure
{
    std::string message;

public:
    SUBFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _SUB_ */
