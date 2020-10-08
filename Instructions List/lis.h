#ifndef _LIS_
#define _LIS_

#include <vector>
#include <string>
#include "../scanner.h"

class LIS
{
    int Instruction;

public:
    LIS(std::vector<Token> tokenLine);
    int getInstruction();
};

class LISFailure
{
    std::string message;

public:
    LISFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _LIS_ */
