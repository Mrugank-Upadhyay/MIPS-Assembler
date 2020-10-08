#ifndef _WORD_
#define _WORD_

#include <vector>
#include "../scanner.h"

class Word
{
    int64_t Instruction;

public:
    Word(std::vector<Token> tokenLine);
    int64_t getInstruction();
};

class WordFailure
{
    std::string message;

public:
    WordFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif /* _WORD_ */
