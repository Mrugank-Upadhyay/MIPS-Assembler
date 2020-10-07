#include "instructions.h"

Instructions::Instructions(std::vector<Token> tokenLine, int PC)
{
    try
    {
        if (tokenLine[0].getKind() == Token::Kind::WORD)
        {
            Word word{tokenLine};
            binaryInstruction = word.getInstruction();
        }
        else if (tokenLine[0].getKind() == Token::Kind::ID)
        {
            if (tokenLine[0].getLexeme() == "jr")
            {
                JR jr{tokenLine};
                binaryInstruction = jr.getInstruction();
            }
            else if (tokenLine[0].getLexeme() == "jalr")
            {
                JALR jalr{tokenLine};
                binaryInstruction = jalr.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "add")
            {
                ADD add{tokenLine};
                binaryInstruction = add.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "sub")
            {
                SUB sub{tokenLine};
                binaryInstruction = sub.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "slt")
            {
                SLT slt{tokenLine};
                binaryInstruction = slt.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "sltu")
            {
                SLTU slt{tokenLine};
                binaryInstruction = slt.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "beq")
            {
                BEQ beq{tokenLine};
                binaryInstruction = beq.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "bne")
            {
                BNE bne{tokenLine};
                binaryInstruction = bne.getInstruction();
            }
        }
    }
    catch (const WordFailure f)
    {
        throw f;
    }

    catch (const ADDFailure f)
    {
        throw f;
    }

    catch (const SUBFailure f)
    {
        throw f;
    }

    catch (const SLTFailure f)
    {
        throw f;
    }

    catch (const SLTUFailure f)
    {
        throw f;
    }

    catch (const JRFailure f)
    {
        throw f;
    }

    catch (const JALRFailure f)
    {
        throw f;
    }

    catch (const BEQFailure f)
    {
        throw f;
    }

    catch (const BNEFailure f)
    {
        throw f;
    }
}

int64_t Instructions::getInstruction()
{
    return binaryInstruction;
}
