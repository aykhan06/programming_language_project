//includes
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

//header files
#include "tokens.h"
#include "lexer.h"
#include "nodes.h"
#include "parser.h"
#include "interpreter.h"
#include "values.h"

//C++ files
#include "tokens.cpp"
#include "lexer.cpp"
#include "nodes.cpp"
#include "parser.cpp"
#include "interpreter.cpp"
#include "values.cpp"

int main()
{
    std::string text, ftxt;
    std::vector<Tokens::Token> tokens;
    std::ifstream file;
    file.open("file.txt", ios::in);
    if (!file.is_open())
    {
        std::cout << "---use 'exit' command for close the program\n"
                  << std::endl;
        while (true)
        {
            std::cout << ">>>";
            getline(std::cin, text);
            Lexer::Lexer lexer(text);
            tokens = lexer.get_tokens();
            Parser::Parser parser(tokens);
            Nodes::Node *tree = parser.parse();
            ////        	 parser.statements();
            //Nodes::print_node(tree);
            if (tree->node_type != Nodes::EmptyNode)
            {
                Interpreter::Interpreter interpreter;
                Values::Number result = interpreter.visit(tree);
                Values::String res = interpreter.visit_(tree);
                Values::print_number(result);
            }
        }
    }
    else
    {
        while (getline(file, ftxt))
        {
            Lexer::Lexer lexer(ftxt);
            tokens = lexer.get_tokens();
            Parser::Parser parser(tokens);
            Nodes::Node *tree = parser.parse();
            ////        	 parser.statements();
            //Nodes::print_node(tree);
            if (tree->node_type != Nodes::EmptyNode)
            {
                Interpreter::Interpreter interpreter;
                Values::Number result = interpreter.visit(tree);
                Values::print_number(result);
            }
        }
        file.close();
    }
}
