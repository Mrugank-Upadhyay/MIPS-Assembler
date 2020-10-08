#ifndef _DIVU_
#define _DIVU_

#include <vector>
#include <string>
#include "scanner.h"

class DIVU
{
    int Instruction;

public:
    DIVU(std::vector<Token> tokenLine);
    int getInstruction();
};

class DIVUFailure
{
    std::string message;

public:
    DIVUFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _DIVU_ */
