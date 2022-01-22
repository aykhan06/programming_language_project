#include <iostream>
#include <string>
#include <sstream>
#include "tokens.h"

namespace Tokens {
    Token::Token(TokenType type, double value) {
        this->type = type;
        this->value = value;
    }
				Token::Token(TokenType type, std::string value){
								this->type = type;
								this->value_ = value;
								if(value=="exit"){exit(0);}else if(value == "cls"){system("clear");}
				}

    Token::operator std::string const() {
        std::string s;
        std::string v;

        switch (type) {
            case NUMBER: s += "NUMBER"; break;
            case PLUS: s += "PLUS"; break;
            case MINUS: s += "MINUS"; break;
            case MULTIPLY: s += "MULTIPLY"; break;
            case MODULUS: s += "MODULUS"; break;
            case DIVIDE: s += "DIVIDE"; break;
            case LPAREN: s += "LPAREN"; break;
            case RPAREN: s += "RPAREN"; break;
            case POWER: s += "POWER"; break;
            case EOF_: s += "EOF"; break;
            case STRING: s += "STRING"; break;
            case IDENTIFIER: s+= "IDENTIFIER"; break;
            case KEYWORD: s+= "KEYWORD"; break;
            case EQ: s += "EQ"; break;
            case EE: s += "EE"; break;
            case NE: s += "NE"; break;
            case GT: s+= "GT"; break;
            case LT: s+= "LT"; break;
           	case GTE: s+= "GTE"; break;
            case LTE: s+= "LTE"; break;
            case COMMA: s+= "COMMA"; break;
            case AND: s+= "AND"; break;
            case OR: s+= "OR"; break;
            case NOT: s+= "NOT"; break;
        }				
    }
};
