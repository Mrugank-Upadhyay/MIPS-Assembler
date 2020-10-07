#ifndef _JALR_
#define _JALR_

#include <vector>
#include <string>
#include "scanner.h"

class JALR
{
    int Instruction;

public:
    JALR(std::vector<Token> tokenLine);
    int getInstruction();
};

class JALRFailure
{
    std::string message;

public:
    JALRFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _JALR_ */
