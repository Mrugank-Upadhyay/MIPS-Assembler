#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "scanner.h"
#include "parser.h"
#include "symbolTable.h"
#include "instructions.h"
#include "instructionLine.h"
#include "encodeLabel.h"

template <typename T>
std::vector<T> slice(std::vector<T> v, int start, int end)
{
  auto first = v.begin() + start;
  auto last = v.begin() + end + 1;

  std::vector<T> vec(first, last);
  return vec;
}

/*
 * C++ Starter code for CS241 A3
 * All code requires C++14, so if you're getting compile errors make sure to
 * use -std=c++14.
 *
 * This file contains the main function of your program. By default, it just
 * prints the scanned list of tokens back to standard output.
 */
int main()
{
  std::string line;
  SymbolTable symbolTable{};
  std::vector<InstructionLine> instructionList;
  int PC = -4;

  bool nullLine = false;

  try
  {
    while (getline(std::cin, line))
    {
      if (line == "")
      {
        continue;
      }
      PC += 4;
      std::vector<Token> tokenLine = scan(line);

      Parser parser{tokenLine, symbolTable, PC};

      if (parser.getSkip() == true)
      {
        PC -= 4;
        continue;
      }

      instructionList.emplace_back(tokenLine, parser.getInstructionStart(), PC);
    }
  }
  catch (const ScanningFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const ParsingFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const SymbolTableFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  std::vector<InstructionLine> instructionListEncoded;

  try
  {
    EncodeLabel encodeLabel{instructionList, symbolTable};
    instructionListEncoded = encodeLabel.getEncodedList();
  }
  catch (const SymbolTableFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  int len = instructionList.size();

  try
  {
    for (auto encodedLine : instructionListEncoded)
    {
      Instructions instruction{slice(encodedLine.getTokenLine(),
                                     encodedLine.getInstructionStart(), encodedLine.getTokenLine().size() - 1),
                               encodedLine.getPC(), symbolTable};

      unsigned char c = instruction.getInstruction() >> 24;
      std::cout << c;
      c = instruction.getInstruction() >> 16;
      std::cout << c;
      c = instruction.getInstruction() >> 8;
      std::cout << c;
      c = instruction.getInstruction();
      std::cout << c;
    }
  }

  catch (const WordFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const ADDFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const SUBFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const SLTFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const SLTUFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const JRFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const JALRFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const BEQFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const BNEFailure &f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const LISFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const MFLOFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const MFHIFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const MULTFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const MULTUFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const DIVFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const DIVUFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const SWFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const LWFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  catch (const SymbolTableFailure f)
  {
    std::cerr << f.what() << std::endl;
    return 1;
  }

  return 0;
}
