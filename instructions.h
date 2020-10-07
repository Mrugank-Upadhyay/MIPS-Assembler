#ifndef _INSTRUCTIONS_
#define _INSTRUCTIONS_

#include <vector>
#include <string>
#include "scanner.h"
#include "add.h"
#include "sub.h"
#include "slt.h"
#include "sltu.h"
#include "jr.h"
#include "jalr.h"
#include "beq.h"
#include "bne.h"
#include "word.h"

class Instructions
{
    int64_t binaryInstruction;

public:
    Instructions(std::vector<Token> tokenLine, int PC);
    int64_t getInstruction();
};

#endif /* _INSTRUCTIONS_ */