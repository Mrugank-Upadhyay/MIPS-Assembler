#include "symbolTable.h"

SymbolTable::SymbolTable() {}

int SymbolTable::find(std::string label)
{
    auto it = symbolTable.find(label);

    if (it != symbolTable.end())
    {
        return it->second;
    }

    throw SymbolTableFailure("ERROR: label does not exist");
}

void SymbolTable::add(std::string label, int value)
{
    std::string Label = label.substr(0, label.length() - 1);

    if (symbolTable.find(Label) == symbolTable.end())
    {
        symbolTable.emplace(Label, value);
        return;
    }
    throw SymbolTableFailure("ERROR: multiple instances of label definition");
}

void SymbolTable::print()
{
    for (auto &label : symbolTable)
    {
        std::cerr << label.first << " " << label.second << std::endl;
    }
}

SymbolTableFailure::SymbolTableFailure(std::string message)
    : message{std::move(message)} {}

const std::string &SymbolTableFailure::what() const
{
    return message;
}