#include "parser.h"
#include <iostream>

Parser::Parser(std::vector<Token> tokenLine, SymbolTable &symbolTable, int PC)
{
    try
    {
        if (tokenLine[0].getKind() == Token::Kind::LABEL)
        {
            int count = 1;
            symbolTable.add(tokenLine[0].getLexeme(), PC);
            for (int i = count; i < tokenLine.size(); i++)
            {
                if (tokenLine[i].getKind() == Token::Kind::LABEL)
                {
                    count++;
                    symbolTable.add(tokenLine[i].getLexeme(), PC);
                    continue;
                }

                break;
            }

            if (count == tokenLine.size())
            {
                skip = true;
            }
            else
            {
                skip = false;
                ParsingRules(tokenLine, count);
            }
        }
        else
        {
            skip = false;
            ParsingRules(tokenLine, 0);
        }
    }
    catch (ParsingFailure pf)
    {
        throw pf;
    }
    catch (SymbolTableFailure stf)
    {
        throw stf;
    }
}

void Parser::ParsingRules(std::vector<Token> tokenLine, int count)
{
    instructionStart = count;

    switch (tokenLine[count].getKind())
    {
    case Token::Kind::WORD:
        if ((count + 2) != int(tokenLine.size()) || (tokenLine.back().getKind() != Token::Kind::INT && tokenLine.back().getKind() != Token::Kind::HEXINT &&
                                                     tokenLine.back().getKind() != Token::Kind::ID))
        {
            throw ParsingFailure("ERROR: invalid instruction / instruction format!");
        }
        break;

    case Token::Kind::ID:
        if (tokenLine[count].getLexeme() == "add" || tokenLine[count].getLexeme() == "sub" ||
            tokenLine[count].getLexeme() == "slt" || tokenLine[count].getLexeme() == "sltu")
        {
            if ((count + 6) != int(tokenLine.size()) || tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 2].getKind() != Token::Kind::COMMA ||
                tokenLine[count + 3].getKind() != Token::Kind::REG || tokenLine[count + 4].getKind() != Token::Kind::COMMA ||
                tokenLine[count + 5].getKind() != Token::Kind::REG)
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "jr" || tokenLine[count].getLexeme() == "jalr")
        {
            if ((count + 2) != int(tokenLine.size()) || tokenLine[count + 1].getKind() != Token::Kind::REG)
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "beq" || tokenLine[count].getLexeme() == "bne")
        {
            if ((count + 6) != int(tokenLine.size()) || (tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 2].getKind() != Token::Kind::COMMA ||
                                                         tokenLine[count + 3].getKind() != Token::Kind::REG || tokenLine[count + 4].getKind() != Token::Kind::COMMA ||
                                                         (tokenLine[count + 5].getKind() != Token::Kind::INT && tokenLine[count + 5].getKind() != Token::Kind::HEXINT &&
                                                          tokenLine[count + 5].getKind() != Token::Kind::ID)))
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "lis" || tokenLine[count].getLexeme() == "mflo" || tokenLine[count].getLexeme() == "mfhi")
        {
            if ((count + 2) != int(tokenLine.size()) || tokenLine[count + 1].getKind() != Token::Kind::REG)
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "mult" || tokenLine[count].getLexeme() == "multu" ||
                 tokenLine[count].getLexeme() == "div" || tokenLine[count].getLexeme() == "divu")
        {
            if ((count + 4) != int(tokenLine.size()) || tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 2].getKind() != Token::Kind::COMMA ||
                tokenLine[count + 3].getKind() != Token::Kind::REG)
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
                return;
            }
        }

        else if (tokenLine[count].getLexeme() == "sw" || tokenLine[count].getLexeme() == "lw")
        {
            if ((count + 7) != int(tokenLine.size()) || tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 2].getKind() != Token::Kind::COMMA ||
                (tokenLine[count + 3].getKind() != Token::Kind::INT && tokenLine[count + 3].getKind() != Token::Kind::HEXINT) || tokenLine[count + 4].getKind() != Token::Kind::LPAREN ||
                tokenLine[count + 5].getKind() != Token::Kind::REG || tokenLine[count + 6].getKind() != Token::Kind::RPAREN)
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        break;

    default:
        throw ParsingFailure("ERROR: invalid line!");
        break;
    }
}

int Parser::getInstructionStart()
{
    return instructionStart;
}

bool Parser::getSkip()
{
    return skip;
}

ParsingFailure::ParsingFailure(std::string message)
    : message{std::move(message)} {}

const std::string &ParsingFailure::what() const
{
    return message;
}
