#ifndef _ENCODELABEL_
#define _ENCODELABEL_

#include "symbolTable.h"
#include "scanner.h"
#include "instructionLine.h"

class EncodeLabel
{
    std::vector<InstructionLine> encodedList;

public:
    EncodeLabel(std::vector<InstructionLine> instructionList, SymbolTable table);
    std::vector<InstructionLine> getEncodedList();
};

#endif /* _ENCODELABEL_ */
