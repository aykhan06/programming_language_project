#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <cstddef>

#define WHITESPACE " \n\t"
#define DIGITS "0123456789"

namespace Lexer {
    class Lexer {
        public:
            std::string text;
            std::size_t index;
            std::string current_char;

            inline Lexer(std::string);

            inline void advance();
            inline std::vector<Tokens::Token> get_tokens();
            inline Tokens::Token get_number();
            inline Tokens::Token make_identifier();
            inline Tokens::Token make_string();
    };

}

#endif // LEXER_H
