#ifndef _INSTRUCTIONS_
#define _INSTRUCTIONS_

#include <vector>
#include <string>
#include "scanner.h"
#include "symbolTable.h"
#include "./Instructions List/add.h"
#include "./Instructions List/sub.h"
#include "./Instructions List/slt.h"
#include "./Instructions List/sltu.h"
#include "./Instructions List/mult.h"
#include "./Instructions List/mult.h"
#include "./Instructions List/multu.h"
#include "./Instructions List/div.h"
#include "./Instructions List/divu.h"
#include "./Instructions List/lis.h"
#include "./Instructions List/mflo.h"
#include "./Instructions List/mfhi.h"
#include "./Instructions List/sw.h"
#include "./Instructions List/lw.h"
#include "./Instructions List/jr.h"
#include "./Instructions List/jalr.h"
#include "./Instructions List/beq.h"
#include "./Instructions List/bne.h"
#include "./Instructions List/word.h"

class Instructions
{
    int64_t binaryInstruction;

public:
    Instructions(std::vector<Token> tokenLine, int PC, SymbolTable table);
    int64_t getInstruction();
};

#endif /* _INSTRUCTIONS_ */