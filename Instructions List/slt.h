#ifndef _SLT_
#define _SLT_

#include <vector>
#include <string>
#include "../scanner.h"

class SLT
{
    int Instruction;

public:
    SLT(std::vector<Token> tokenLine);
    int getInstruction();
};

class SLTFailure
{
    std::string message;

public:
    SLTFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _SLT_ */
