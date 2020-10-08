#ifndef _JR_
#define _JR_

#include <vector>
#include <string>
#include "../scanner.h"

class JR
{
    int Instruction;

public:
    JR(std::vector<Token> tokenLine);
    int getInstruction();
};

class JRFailure
{
    std::string message;

public:
    JRFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _JR_ */
