#ifndef _DIV_
#define _DIV_

#include <vector>
#include <string>
#include "../scanner.h"

class DIV
{
    int Instruction;

public:
    DIV(std::vector<Token> tokenLine);
    int getInstruction();
};

class DIVFailure
{
    std::string message;

public:
    DIVFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _DIV_ */
