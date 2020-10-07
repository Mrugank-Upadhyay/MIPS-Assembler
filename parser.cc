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
        if ((tokenLine.back().getKind() != Token::Kind::INT && tokenLine.back().getKind() != Token::Kind::HEXINT && tokenLine.back().getKind() != Token::Kind::ID) || (count + 2) != int(tokenLine.size()))
        {
            throw ParsingFailure("ERROR: invalid instruction / instruction format!");
        }
        break;

    case Token::Kind::ID:
        if (tokenLine[count].getLexeme() == "add")
        {
            if (tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 3].getKind() != Token::Kind::REG ||
                tokenLine[count + 5].getKind() != Token::Kind::REG || (count + 6) != int(tokenLine.size()))
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "sub")
        {
            if (tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 3].getKind() != Token::Kind::REG ||
                tokenLine[count + 5].getKind() != Token::Kind::REG || (count + 6) != int(tokenLine.size()))
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "slt")
        {
            if (tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 3].getKind() != Token::Kind::REG ||
                tokenLine[count + 5].getKind() != Token::Kind::REG || (count + 6) != int(tokenLine.size()))
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "sltu")
        {
            if (tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 3].getKind() != Token::Kind::REG ||
                tokenLine[count + 5].getKind() != Token::Kind::REG || (count + 6) != int(tokenLine.size()))
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "jr")
        {
            if (tokenLine[count + 1].getKind() != Token::Kind::REG || (count + 2) != int(tokenLine.size()))
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "jalr")
        {
            if (tokenLine[count + 1].getKind() != Token::Kind::REG || (count + 2) != int(tokenLine.size()))
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "beq")
        {
            if (tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 3].getKind() != Token::Kind::REG ||
                (tokenLine[count + 5].getKind() != Token::Kind::INT && tokenLine[count + 5].getKind() != Token::Kind::HEXINT &&
                 tokenLine[count + 5].getKind() != Token::Kind::ID) ||
                (count + 6) != int(tokenLine.size()))
            {
                throw ParsingFailure("ERROR: invalid Instruction / instruction format!");
            }
        }

        else if (tokenLine[count].getLexeme() == "bne")
        {
            if (tokenLine[count + 1].getKind() != Token::Kind::REG || tokenLine[count + 3].getKind() != Token::Kind::REG ||
                (tokenLine[count + 5].getKind() != Token::Kind::INT && tokenLine[count + 5].getKind() != Token::Kind::HEXINT &&
                 tokenLine[count + 5].getKind() != Token::Kind::ID) ||
                (count + 6) != int(tokenLine.size()))
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
