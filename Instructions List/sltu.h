#ifndef _SLTU_
#define _SLTU_

#include <vector>
#include <string>
#include "../scanner.h"

class SLTU
{
    int Instruction;

public:
    SLTU(std::vector<Token> tokenLine);
    int getInstruction();
};

class SLTUFailure
{
    std::string message;

public:
    SLTUFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _SLTU_ */
