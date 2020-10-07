#ifndef _ADD_
#define _ADD_

#include <vector>
#include <string>
#include "scanner.h"

class ADD
{
    int Instruction;

public:
    ADD(std::vector<Token> tokenLine);
    int getInstruction();
};

class ADDFailure
{
    std::string message;

public:
    ADDFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _ADD_ */
