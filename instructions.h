#ifndef _INSTRUCTIONS_
#define _INSTRUCTIONS_

#include <vector>
#include <string>
#include "scanner.h"
#include "symbolTable.h"
#include "./Instructions/add.h"
#include "./Instructions/sub.h"
#include "./Instructions/slt.h"
#include "./Instructions/sltu.h"
#include "./Instructions/mult.h"
#include "./Instructions/mult.h"
#include "./Instructions/multu.h"
#include "./Instructions/div.h"
#include "./Instructions/divu.h"
#include "./Instructions/lis.h"
#include "./Instructions/mflo.h"
#include "./Instructions/mfhi.h"
#include "./Instructions/sw.h"
#include "./Instructions/lw.h"
#include "./Instructions/jr.h"
#include "./Instructions/jalr.h"
#include "./Instructions/beq.h"
#include "./Instructions/bne.h"
#include "./Instructions/word.h"

class Instructions
{
    int64_t binaryInstruction;

public:
    Instructions(std::vector<Token> tokenLine, int PC, SymbolTable table);
    int64_t getInstruction();
};

#endif /* _INSTRUCTIONS_ */