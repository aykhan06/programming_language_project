#ifndef TOKENS_H
#define TOKENS_H
#include <string>

namespace Tokens {
	std::string value_;
 enum TokenType {
  NUMBER,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  MODULUS,
  LPAREN,
  COLON,
  RPAREN,
  POWER,
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
 };
using namespace std;
 class Token {
  public:
   TokenType type;
   string value_;
   double value;
   Token(TokenType, double = 0);
   Token(TokenType, string);
 
   operator string const();
  	bool matches(TokenType,std::string);
 };
};

#endif // TOKENS_H
