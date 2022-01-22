#include <string>
#include <vector>
#include <iostream>

#include "parser.h"
#include "tokens.h"
#include "nodes.h"
#include "values.h"


namespace Parser {
    Parser::Parser(std::vector<Tokens::Token> tokens) {
        tokens.push_back(Tokens::Token(Tokens::EOF_));
        this->tokens = tokens;
        index = 0;
    }

    Parser::~Parser() {
        Nodes::free_node(node);
    }

    void Parser::advance() {
        index++;
    }

    Tokens::Token Parser::current() {
        return tokens[index];
    }

    Nodes::Node *Parser::parse() {
        if (current().type == Tokens::EOF_) {
            PARSER_EMPTY_NODE;
            return node;
        }
        
        node = expr();

                        
        return node;
    }

    Nodes::Node *Parser::expr() {
        Nodes::Node *result = term();
        while (current().type != Tokens::EOF_ && (current().type == Tokens::PLUS ||
						current().type == Tokens::MINUS||current().type == Tokens::KEYWORD||current().type == Tokens::IDENTIFIER||
								current().type == Tokens::STRING))
								{
            if (current().type == Tokens::PLUS) {
                advance();
                result = new Nodes::Node(Nodes::AddNode, result, term());
              }
    
             else if (current().type == Tokens::MINUS) {
                advance();
                result = new Nodes::Node(Nodes::SubtractNode, result, term());
              }
				     else if(current().type == Tokens::KEYWORD&&current().value_=="elif"){
														result = PARSER_EMPTY_NODE;
														advance();
				     }
				     else if (current().type==Tokens::KEYWORD&&current().value_=="while"){
				       result = while_expr();
				     }
        }

        return result;
   }

    Nodes::Node *Parser::term() {
        Nodes::Node *result = exponent();
        while (current().type != Tokens::EOF_ && (current().type == Tokens::MULTIPLY || 
								current().type == Tokens::DIVIDE||current().type == Tokens::MODULUS||current().type == Tokens::EE
								||current().type == Tokens::NE||current().type == Tokens::GT||current().type == Tokens::LT
								||current().type == Tokens::GTE||current().type == Tokens::LTE||current().value_=="and"
								||current().value_=="or"||current().value_=="not"||current().type==Tokens::OR||current().type==Tokens::AND||current().type==Tokens::NOT
								||current().type == Tokens::MULTIPLY_EQ)) {
            if (current().type == Tokens::MULTIPLY) {
                advance();
                result = new Nodes::Node(Nodes::MultiplyNode, result, exponent());
            } else if (current().type == Tokens::DIVIDE) {
                advance();
                result = new Nodes::Node(Nodes::DivideNode, result, exponent());
            } else if (current().type == Tokens::MODULUS) {
                advance();
                result = new Nodes::Node(Nodes::ModulusNode, result, term());
            }
              else if (current().type == Tokens::EE) {
                advance();
                result = new Nodes::Node(Nodes::EENode, result, term());
            } else if (current().type == Tokens::NE) {
                advance();
                result = new Nodes::Node(Nodes::NENode, result, exponent());
            }else if (current().type == Tokens::GT) {
                advance();
                result = new Nodes::Node(Nodes::GTNode, result, term());
            }
             else if (current().type == Tokens::LT) {
                advance();
                result = new Nodes::Node(Nodes::LTNode, result, exponent());
            } else if (current().type == Tokens::GTE) {
                advance();
                result = new Nodes::Node(Nodes::GTENode, result, exponent());
            }else if (current().type == Tokens::LTE) {
                advance();
                result = new Nodes::Node(Nodes::LTENode, result, term());
            }
            else if (current().value_=="and"|| current().type==Tokens::AND) {
                advance();
                result = new Nodes::Node(Nodes::AndNode, result, expr());
            }
            else if (current().value_=="or"|| current().type==Tokens::OR) {
                advance();
                result = new Nodes::Node(Nodes::OrNode, result, factor());
            }
            else if (current().value_=="not"|| current().type==Tokens::NOT) {
                advance();
                result = new Nodes::Node(Nodes::NotNode,NULL,factor());
            }
        }

        return result;
    }

    Nodes::Node *Parser::exponent() {
        Nodes::Node *result = factor();

        while (current().type != Tokens::EOF_ && current().type == Tokens::POWER) {
            if (current().type == Tokens::POWER) {
                advance();
                result = new Nodes::Node(Nodes::PowerNode, result, factor());
            }
        }

        return result;
    }

    Nodes::Node *Parser::factor() {
        Tokens::Token current_token = current();
        if (current_token.type == Tokens::LPAREN) {
            advance();
            Nodes::Node *result = expr();

            if (current().type != Tokens::RPAREN) {
                PARSER_EMPTY_NODE;
                std::cout<<"Syntax error"<<std::endl;
            }

            advance();
            return result;
        } else if (current_token.type == Tokens::NUMBER) {
            advance();
            return new Nodes::Node(Nodes::NumberNode, current_token.value);
        } else if (current_token.type == Tokens::PLUS) {
            advance();
            return new Nodes::Node(Nodes::PlusNode, factor());
        } else if (current_token.type == Tokens::MINUS) {
            advance();
            return new Nodes::Node(Nodes::MinusNode, factor());
            
        }else if(current().type == Tokens::KEYWORD&&current().value_=="def") {
       	using namespace std;
       				advance();
       				if(current().type == Tokens::IDENTIFIER){
       					std::string var_name = current().value_;
       					advance();
       					if(current().type==Tokens::EQ){
       						advance();
       						return new Nodes::Node(Nodes::VarAssignNode,expr(),var_name);}
												
												else if(current().type == Tokens::LPAREN){
													std::cout<<"0"<<std::endl;
													std::vector<std::string>arg_name_toks;
													advance();
													if(current().type == Tokens::IDENTIFIER){
														while(current().type!=Tokens::RPAREN){
															if(current().type == Tokens::IDENTIFIER){
																arg_name_toks.push_back(current().value_);
																advance();}
															if(current().type==Tokens::COMMA){
																}
														}
														if(current().type==Tokens::COLON){
														for(int i=0;i<arg_name_toks.size();i++){
															cout<<arg_name_toks[i]<<endl;
														}advance();}else{
															SyntaxError("expected",":");
														}
														return PARSER_EMPTY_NODE;
											}
												
												else{
													SyntaxError("invalid syntax", "");
													return PARSER_EMPTY_NODE;
												}
											}
											
											
											else{
													SyntaxError("invalid syntax", "");
													return PARSER_EMPTY_NODE;
											}
										}
									}
		else if(current().type==Tokens::IDENTIFIER){
			std::string current_value = current().value_;
			advance();
			if(current().type==Tokens::EQ){
			  advance();
			  return new Nodes::Node(Nodes::VarAssignNode,expr(),current_value);
			}
			return new Nodes::Node(Nodes::VarAccessNode,current_value);
		}
 		else if (current_token.type == Tokens::STRING) {
        		std::string current_value = current().value_;
							 advance();
							 std::cout<<current_value<<std::endl;
							return PARSER_EMPTY_NODE;
								}
    else if(current().type==Tokens::KEYWORD&&current().value_=="if"){
      return if_expr_cases();
    }
    else if(current().type == Tokens::KEYWORD&&current().value_ == "while"){
    		return while_expr();
				}

        PARSER_EMPTY_NODE;
    }
 Nodes::Node *Parser::if_expr_cases(){
 	using namespace std;
 	try{
        std::vector<Nodes::Node *>cases;
        advance();
        Nodes::Node *condition;
        Nodes::Node *body;
        if (current().type == Tokens::LPAREN) {
            advance();
            condition = expr();

            if (current().type != Tokens::RPAREN) {
                SyntaxError("expected condition or",")");
                return PARSER_EMPTY_NODE;
            }
           advance();
           if(current().type==Tokens::COLON){
             advance();
             body = expr();
             while(current().type==Tokens::KEYWORD||current().value_=="elif"){
              advance();
              cout<<"salam"<<endl;
             }
             cases.push_back((condition,body));
														return new Nodes::Node(Nodes::IfNode,condition,body);
//													}
          }else{
             SyntaxError("expected",":");    
             return PARSER_EMPTY_NODE;
           }
          }else{
             SyntaxError("expected","(");    
             return PARSER_EMPTY_NODE;}
      return new Nodes::Node(Nodes::IfNode,condition,body);
     }catch(std::string error){
     	cerr<<error<<endl;
					}
	}
 Nodes::Node *Parser::while_expr(){
 	using namespace std;
        std::vector<Nodes::Node *>cases;
        advance();
        Nodes::Node *condition;
        Nodes::Node *body;
        if (current().type == Tokens::LPAREN) {
            advance();
            condition = expr();

            if (current().type != Tokens::RPAREN) {
                SyntaxError("expected condition or",")");
                return PARSER_EMPTY_NODE;
            }
           advance();
           if(current().type==Tokens::COLON){
             advance();
             body = expr();
             cases.push_back((condition,body));
          }else{
             SyntaxError("expected",":");    
             return PARSER_EMPTY_NODE;
           }
          }else{
             SyntaxError("expected","(");    
             return PARSER_EMPTY_NODE;}
      return new Nodes::Node(Nodes::WhileNode,condition,body);
	}
}
