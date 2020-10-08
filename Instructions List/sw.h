#ifndef _SW_
#define _SW_

#include <vector>
#include <string>
#include <cmath>
#include "../scanner.h"

class SW
{
    int Instruction;

public:
    SW(std::vector<Token> tokenLine);
    int getInstruction();
};

class SWFailure
{
    std::string message;

public:
    SWFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _SW_ */
