#ifndef _INSTRUCTIONS_
#define _INSTRUCTIONS_

#include <vector>
#include <string>
#include "scanner.h"
#include "symbolTable.h"
#include "add.h"
#include "sub.h"
#include "slt.h"
#include "sltu.h"
#include "mult.h"
#include "multu.h"
#include "div.h"
#include "divu.h"
#include "lis.h"
#include "mflo.h"
#include "mfhi.h"
#include "sw.h"
#include "lw.h"
#include "jr.h"
#include "jalr.h"
#include "beq.h"
#include "bne.h"
#include "word.h"

class Instructions
{
    int64_t binaryInstruction;

public:
    Instructions(std::vector<Token> tokenLine, int PC, SymbolTable table);
    int64_t getInstruction();
};

#endif /* _INSTRUCTIONS_ */