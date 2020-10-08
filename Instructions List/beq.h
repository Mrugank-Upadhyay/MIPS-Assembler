#ifndef _BEQ_
#define _BEQ_

#include <vector>
#include <string>
#include <cmath>
#include "../scanner.h"
#include "../symbolTable.h"

class BEQ
{
    int Instruction;

public:
    BEQ(std::vector<Token> tokenLine, int PC, SymbolTable table);
    int getInstruction();
};

class BEQFailure
{
    std::string message;

public:
    BEQFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _BEQ_ */
