#ifndef _MULTU_
#define _MULTU_

#include <vector>
#include <string>
#include "../scanner.h"

class MULTU
{
    int Instruction;

public:
    MULTU(std::vector<Token> tokenLine);
    int getInstruction();
};

class MULTUFailure
{
    std::string message;

public:
    MULTUFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _MULTU_ */
