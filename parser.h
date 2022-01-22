#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include "tokens.h"
#include "nodes.h"

#define PARSER_EMPTY_NODE node = new Nodes::Node(Nodes::EmptyNode)

namespace Parser {
  class Parser {
   public:
    std::vector<Tokens::Token> tokens;
    std::size_t index;
    Nodes::Node *node;

   inline Parser(std::vector<Tokens::Token>);
   inline ~Parser();
   inline void advance();
   inline Tokens::Token current();
   inline Nodes::Node *parse();
   inline Nodes::Node *expr();
   inline Nodes::Node *term();
   inline Nodes::Node *exponent();
   inline Nodes::Node *factor();
   inline Nodes::Node *atom();
   inline Nodes::Node *if_expr_cases();
   inline Nodes::Node *while_expr();
    };
}

#endif // PARSER_H
