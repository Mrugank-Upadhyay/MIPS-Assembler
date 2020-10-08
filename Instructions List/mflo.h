#ifndef _MFLO_
#define _MFLO_

#include <vector>
#include <string>
#include "../scanner.h"

class MFLO
{
    int Instruction;

public:
    MFLO(std::vector<Token> tokenLine);
    int getInstruction();
};

class MFLOFailure
{
    std::string message;

public:
    MFLOFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _MFLO_ */
