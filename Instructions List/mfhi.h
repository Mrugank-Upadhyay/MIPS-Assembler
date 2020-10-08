#ifndef _MFHI_
#define _MFHI_

#include <vector>
#include <string>
#include "../scanner.h"

class MFHI
{
    int Instruction;

public:
    MFHI(std::vector<Token> tokenLine);
    int getInstruction();
};

class MFHIFailure
{
    std::string message;

public:
    MFHIFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _MFHI_ */
