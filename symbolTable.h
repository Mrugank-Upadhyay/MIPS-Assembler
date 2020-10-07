#ifndef _SYMBOLTABLE_
#define _SYMBOLTABLE_

#include <map>
#include <string>
#include <iostream>

class SymbolTable {
    std::map<std::string, int> symbolTable;
public:
    SymbolTable();
    int find(std::string label);
    void add(std::string label, int value);
    void print();
};



class SymbolTableFailure {
    std::string message;

public:
    SymbolTableFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string& what() const;
};

#endif
