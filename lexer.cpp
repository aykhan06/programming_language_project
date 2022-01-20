#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <cstdlib>
#include "tokens.h"
#include "lexer.h"
#include "errors.cpp"

int compare(std::string name)
{
	std::vector<std::string> keywords;
	keywords.push_back("def");
	keywords.push_back("del");
	keywords.push_back("for");
	keywords.push_back("while");
	keywords.push_back("exit");
	keywords.push_back("use");
	keywords.push_back("new");
	keywords.push_back("for");
	keywords.push_back("break");
	keywords.push_back("if");
	keywords.push_back("elif");
	keywords.push_back("else");
	keywords.push_back("and");
	keywords.push_back("or");
	keywords.push_back("not");
	for (int i = 0; i < keywords.size(); i++)
	{
		std::string key = keywords[i];
		if (name == key)
		{
			return 1;
			exit(0);
		}
	}
	return 0;
}

namespace Lexer
{
Lexer::Lexer(std::string text)
{
	this->text = text;
	index = 0;
	advance();
}

void Lexer::advance()
{
	current_char = text[index++];
}

std::vector<Tokens::Token> Lexer::get_tokens()
{
	std::vector<Tokens::Token> tokens;
	while (index <= text.length())
	{
		if (current_char.find_first_of(WHITESPACE) != std::string::npos)
		{
			advance();
		}
		else if (current_char == "." || current_char.find_first_of(DIGITS) != std::string::npos)
		{
			tokens.push_back(get_number());
		}
		else if (current_char == "+")
		{
			tokens.push_back(Tokens::Token(Tokens::PLUS));
			advance();
		}
		else if (current_char == "-")
		{
			tokens.push_back(Tokens::Token(Tokens::MINUS));
			advance();
		}
		else if (current_char == "%")
		{
			tokens.push_back(Tokens::Token(Tokens::MODULUS));
			advance();
		}
		else if (current_char == "*")
		{
			advance();
			if (current_char == "*")
			{
				advance();
				tokens.push_back(Tokens::Token(Tokens::POWER));
			}
			else
				tokens.push_back(Tokens::Token(Tokens::MULTIPLY));
		}
		else if (current_char == "=")
		{
			advance();
			if (current_char == "=")
			{
				tokens.push_back(Tokens::Token(Tokens::EE));
				advance();
			}
			else
				tokens.push_back(Tokens::Token(Tokens::EQ));
		}
		else if(current_char == ":"){
			advance();
			tokens.push_back(Tokens::Token(Tokens::COLON));
		}
		else if(current_char == ","){
			advance();
			tokens.push_back(Tokens::Token(Tokens::COMMA));
		}
		else if (current_char == ">")
		{
			advance();
			if (current_char == "=")
			{
				advance();
				tokens.push_back(Tokens::Token(Tokens::GTE));
			}
			else
				tokens.push_back(Tokens::Token(Tokens::GT));
		}
		else if (current_char == "<")
		{
			advance();
			if (current_char == "=")
			{
				advance();
				tokens.push_back(Tokens::Token(Tokens::LTE));
			}
			else
				tokens.push_back(Tokens::Token(Tokens::LT));
		}
		else if (current_char == "!")
		{
			advance();
			if (current_char == "=")
			{
				advance();
				tokens.push_back(Tokens::Token(Tokens::NE));
			}
			else{
				throw std::string("'=' after '!'");}
		}
		else if (current_char == "/")
		{
			tokens.push_back(Tokens::Token(Tokens::DIVIDE));
			advance();
		}
		else if (current_char == "(")
		{
			advance();
			tokens.push_back(Tokens::Token(Tokens::LPAREN));
		}
		else if (current_char == ")")
		{
			advance();
			tokens.push_back(Tokens::Token(Tokens::RPAREN));
		}
		else if (isalpha(current_char.at(0)))
		{
			tokens.push_back(make_identifier());
		}
		else if (current_char == "'")
		{
			tokens.push_back(make_string());
		}
		else if(current_char == "\"")
		{
		  tokens.push_back(make_string());
		}
		else
		{
			IllegalCharError("illegal character",current_char);
			advance();
		}
	}

	return tokens;
}

Tokens::Token Lexer::get_number()
{
	int decimal_point_count = 0;
	std::string number_str = current_char;
	advance();

	while (index <= text.length() && (current_char == "." || current_char.find_first_of(DIGITS) != std::string::npos))
	{
		if (current_char == ".")
			if (++decimal_point_count > 1)
				break;

		number_str += current_char;
		advance();
	}

	if (number_str[0] == '.')
		number_str = "0" + number_str;

	if (number_str[number_str.length() - 1] == '.')
	{
		number_str += "0";
	}
	const char *num_char = number_str.c_str();
	double num_double = atof(num_char);
	return Tokens::Token(Tokens::NUMBER, num_double);
}
Tokens::Token Lexer::make_identifier()
{
	std::string identifier;
	while (isalpha(current_char.at(0)))
	{
		identifier.append(current_char);
		advance();
	}
	if (compare(identifier) == 0)
	{
		//advance();
	return Tokens::Token(Tokens::IDENTIFIER, identifier);
	}
	else
	{
		advance();
	return Tokens::Token(Tokens::KEYWORD, identifier);
	}
}
Tokens::Token Lexer::make_string()
{
	using namespace std;
	string str;
	advance();
	str.append("'");
	while (current_char != "'")
	{
		if (current_char == "\\")
		{
			advance();
			if (current_char == "n")
			{
				str.append("\n");
				advance();
				if (current_char == "'"){continue;}
			}
			else if(current_char == "'"){
			  continue;
			}
			else if (current_char == "t")
			{
				str.append("\t");
				advance();
				if (current_char == "'"){continue;}
			}
			else if (current_char == "s")
			{
				str.append(" ");
				advance();
				if (current_char == "'"){continue;}
			}
			else if (current_char == "\\")
			{
				str.append("\\");
				continue;
			}
		}
		str.append(current_char);
		advance();
	}
	str.append("'");
//	std::cout << "\"" << std::endl;
	advance();
	return Tokens::Token(Tokens::STRING, str);
}
} // namespace Lexer
