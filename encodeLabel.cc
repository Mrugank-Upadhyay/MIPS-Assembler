#include "encodeLabel.h"

EncodeLabel::EncodeLabel(std::vector<InstructionLine> intstructionList, SymbolTable table)
{
    bool keepLabel = false;

    for (auto line : intstructionList)
    {
        std::vector<Token> tokenLine = line.getTokenLine();
        std::vector<Token> newLine;
        for (auto token : tokenLine)
        {
            if (token.getKind() == Token::Kind::ID &&
                (token.getLexeme() != "add" && token.getLexeme() != "sub" &&
                 token.getLexeme() != "mult" && token.getLexeme() != "multu" &&
                 token.getLexeme() != "div" && token.getLexeme() != "divu" &&
                 token.getLexeme() != "slt" && token.getLexeme() != "sltu" &&
                 token.getLexeme() != "lis" && token.getLexeme() != "mflo" &&
                 token.getLexeme() != "mfhi" && token.getLexeme() != "sw" &&
                 token.getLexeme() != "lw" && token.getLexeme() != "beq" &&
                 token.getLexeme() != "bne" && token.getLexeme() != "jr" &&
                 token.getLexeme() != "jalr") &&
                (keepLabel == false))
            {
                int64_t lineNum = table.find(token.getLexeme());
                newLine.emplace_back(Token::Kind::INT, std::to_string(lineNum));
            }

            else
            {
                if (token.getLexeme() == "beq" || token.getLexeme() == "bne")
                {
                    keepLabel = true;
                }
                newLine.push_back(token);
            }
        }
        keepLabel = false;
        encodedList.emplace_back(newLine, line.getInstructionStart(), line.getPC());
    }
}

std::vector<InstructionLine> EncodeLabel::getEncodedList()
{
    return encodedList;
}