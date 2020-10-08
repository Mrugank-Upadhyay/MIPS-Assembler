#include "instructions.h"

Instructions::Instructions(std::vector<Token> tokenLine, int PC, SymbolTable table)
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
                BEQ beq{tokenLine, PC, table};
                binaryInstruction = beq.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "bne")
            {
                BNE bne{tokenLine, PC, table};
                binaryInstruction = bne.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "lis")
            {
                LIS lis{tokenLine};
                binaryInstruction = lis.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "mflo")
            {
                MFLO mflo{tokenLine};
                binaryInstruction = mflo.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "mfhi")
            {
                MFHI mfhi{tokenLine};
                binaryInstruction = mfhi.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "mult")
            {
                MULT mult{tokenLine};
                binaryInstruction = mult.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "multu")
            {
                MULTU multu{tokenLine};
                binaryInstruction = multu.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "div")
            {
                DIV div{tokenLine};
                binaryInstruction = div.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "divu")
            {
                DIVU divu{tokenLine};
                binaryInstruction = divu.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "sw")
            {
                SW sw{tokenLine};
                binaryInstruction = sw.getInstruction();
            }

            else if (tokenLine[0].getLexeme() == "lw")
            {
                LW lw{tokenLine};
                binaryInstruction = lw.getInstruction();
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

    catch (const LISFailure f)
    {
        throw f;
    }

    catch (const MFLOFailure f)
    {
        throw f;
    }

    catch (const MFHIFailure f)
    {
        throw f;
    }

    catch (const MULTFailure f)
    {
        throw f;
    }

    catch (const MULTUFailure f)
    {
        throw f;
    }

    catch (const DIVFailure f)
    {
        throw f;
    }

    catch (const DIVUFailure f)
    {
        throw f;
    }

    catch (const SWFailure f)
    {
        throw f;
    }

    catch (const LWFailure f)
    {
        throw f;
    }

    catch (const SymbolTableFailure f)
    {
        throw f;
    }
}

int64_t Instructions::getInstruction()
{
    return binaryInstruction;
}
