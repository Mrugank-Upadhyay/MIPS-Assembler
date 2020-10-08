#ifndef CS241_SCANNER_H
#define CS241_SCANNER_H
#include <string>
#include <vector>
#include <set>
#include <cstdint>
#include <ostream>

class Token;

std::vector<Token> scan(const std::string &input);
class Token
{
public:
  enum Kind
  {
    ID = 0,
    LABEL,
    WORD,
    COMMA,
    LPAREN,
    RPAREN,
    INT,
    HEXINT,
    REG,
    WHITESPACE,
    COMMENT
  };

private:
  Kind kind;
  std::string lexeme;

public:
  Token(Kind kind, std::string lexeme);

  Kind getKind() const;
  const std::string &getLexeme() const;

  // Only on INT, HEXINT, and REG
  int64_t toLong() const;
};

std::ostream &operator<<(std::ostream &out, const Token &tok);

class ScanningFailure
{
  std::string message;

public:
  ScanningFailure(std::string message);

  // Returns the message associated with the exception.
  const std::string &what() const;
};

#endif
