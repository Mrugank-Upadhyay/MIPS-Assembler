# MIPS-Assembler
A MIPS assembler that converts **MIPS Assembly Language** into **MIPS Machine Language**.

## What I Learned
From this project, I learned a lot about how low level programs function and the bridging between high level languages and machine code via assemblers. It not only taught me the process of Tokenization, Parsing, and Semantic Analysis, but it also taught me how Deterministic Finite Automatas (DFAs) can be used in the tokenization process. However, this rabbit hole not only lead me to learn the programming aspect but also the hardware aspect by simply searching about information related to Registers. Learning about Registers led me to learn how digital logic is utilized via Transistors, specifically CMOS, PMOS, and NMOS and their interactions in building circuits that can create the Register structure, specifically via Decoders and Multiplexors. All in all, this project was not simply one on coding an assembler, it was more so about learning the inner workings of computers on a level that is typically forgotten in day-to-day life!

## How It Works
There are 2 main stages to the assembler. First is the Analysis stage which is actually a multi-stage process, and then there is the Synthesis stage.

### Analysis Stage
In the analysis stage, we first deal with reading in the assembly language and comprehending it. This means first going through a tokenization process which breaks each line
of code into tokens. Tokenization is done using an algorithm that is taught with **DFAs** called **Simplified Maximal Munch**. E.g add $1, $2, $3 gets broken into an ID token with a lexeme of "add", a REG token with a lexeme of "$1,", a REG token with a lexeme of "$2,", and a REG token with a lexeme of "$3,".

The next sub-stage is **Parsing**. In my implementation, I have combined the parsing with the tokenization so instead of first tokenizing the entire program, then parsing it, then evaluating it, we tokenize and parse each line. This ensure we aren't needlessly looping through the program again. In parsing, I match each line to a certain sequence of tokens representing the shape of a correct instruction line. This means that instead of checking all the ways the line is incorrect, I simply have to match the line to its generic form and ensure it matches said form.

Finally, after parsing, we have to perform **Semantic Analysis**. This sub-stage is meant to ensure that we don't recieve duplicate Labels in our assembly code and it also acts to replace labels incorporated into instructions with their correct values / offsets. 

For example:

004 Procedure:
...
012 beq $3, $4, Procedure

Here we must allow our branch-on-equal statement to jump to the Procedure label defined on line 004, but it must correctly calculate its offset.

## Synthesis Stage
This final stage occurs once we know the assembly code input is valid code and we are able to generate its output. In this stage, we look at the lines of instructions and for each instruction we generate its **Opcode**, **RD**, **RS**, **RT**, **IMM**, and **Func-Code**, leaving out any destination, source, or target register as well as any immediate value as necessary.

Once the correct integers are generated for the instruction, they are concatenated together using Bitwise OR and outputted in binary format.

And there we have it! A fully functioning MIPS Assembler in C++.

## Things To Improve In The Future
I think I really should work on cleaning up my code and file structure so that there are fewer points of potential breakage. This might mean revamping my instruction list and having abstract base classes for grouped instructions such as "add", "sub", "slt", and "sltu" since they work pretty much the same with only changes in their function code. That would make my code much more readable and allow it to better follow the **SOLID** principles.
