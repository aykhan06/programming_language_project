#ifndef TOKENS_H
#define TOKENS_H
#include <string>

namespace Tokens {
	std::string value_;
 enum TokenType {
  NUMBER,
  PLUS,
  PLUS_EQ,
  MINUS,
  MINUS_EQ,
  MULTIPLY,
  MULTIPLY_EQ,
  DIVIDE,
  DIVIDE_EQ,
  MODULUS,
  MODULUS_EQ,
  LPAREN,
  COLON,
  RPAREN,
  POWER,
  POWER_EQ,
  EOF_,
  IDENTIFIER,
  KEYWORD,
  STRING,
  EQ,
  EE,
  NE,
  GT,
  LT,
  GTE,
  LTE,
  COMMA,
  NOT,
  AND,
  OR
 };
using namespace std;
 class Token {
  public:
   TokenType type;
   string value_;
   double value;
  inline Token(TokenType, double = 0);
  inline Token(TokenType, string);
 
   operator string const();
  	bool matches(TokenType,std::string);
 };
};

#endif // TOKENS_H
