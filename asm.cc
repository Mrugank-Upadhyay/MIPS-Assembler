#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "scanner.h"
#include "parser.h"
#include "symbolTable.h"
#include "instructions.h"
#include "instructionLine.h"

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

  bool prevLabel = false;

  try
  {
    while (getline(std::cin, line))
    {
      if (line == "")
      {
        continue;
      }

      if (prevLabel != true)
      {
        PC += 4;
      }
      std::vector<Token> tokenLine = scan(line);

      Parser parser{tokenLine, symbolTable, PC};
      parser.getContainsLabel() ? prevLabel = true : prevLabel = false;
      if (parser.getSkip() == true)
      {
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

  int len = instructionList.size();

  try
  {
    for (int i = 0; i < len; i++)
    {
      Instructions instruction{slice(instructionList[i].getTokenLine(),
                                     instructionList[i].getInstructionStart(), instructionList[i].getTokenLine().size() - 1),
                               instructionList[i].getPC()};
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

  symbolTable.print();

  return 0;
}
