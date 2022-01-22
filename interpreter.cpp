#include <string>
#include <cmath>
#include <iostream>

#include "nodes.h"
#include "values.h"
#include "interpreter.h"
#include "symboltable.cpp"
static SymbolTable symbol;
namespace Interpreter {
    Values::Number Interpreter::visit(Nodes::Node *node) {
        switch (node->node_type) {
            case Nodes::NumberNode:
                return Values::Number(node->value);
            case Nodes::AddNode:
                return visit_add_node(node);
            case Nodes::SubtractNode:
                return visit_subtract_node(node);
            case Nodes::MultiplyNode:
                return visit_multiply_node(node);
            case Nodes::DivideNode:
                return visit_divide_node(node);
            case Nodes::ModulusNode:
            				return visit_modulus_node(node);
            case Nodes::PowerNode:
                return visit_power_node(node);
            case Nodes::PlusNode:
                return visit_plus_node(node);
            case Nodes::MinusNode:
                return visit_minus_node(node);
            case Nodes::EENode:
                return visit_ee_node(node);
            case Nodes::NENode:
            				return visit_ne_node(node);
            case Nodes::GTNode:
                return visit_gt_node(node);
            case Nodes::LTNode:
                return visit_lt_node(node);
            case Nodes::GTENode:
                return visit_gte_node(node);
            case Nodes::LTENode:
            				return visit_lte_node(node);
            case Nodes::VarAssignNode:
            				return visit_var_assign_node(node);
            case Nodes::VarAccessNode:
            				return visit_var_access_node(node);
            case Nodes::AndNode:
            				return visit_and_node(node);
            case Nodes::OrNode:
            				return visit_or_node(node);
            case Nodes::NotNode:
            				return visit_not_node(node);
            case Nodes::IfNode:
                    return visit_if_node(node);
            case Nodes::WhileNode:
                    return visit_while_node(node);
            default:
                throw std::string("Invalid node");
        }
    }
    Values::Number Interpreter::visit_add_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value + visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_subtract_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value - visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_ee_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value == visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_ne_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value != visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_gt_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value > visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_lt_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value < visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_gte_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value >= visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_lte_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value <= visit(node->node_b).value);
    }

   Values::Number Interpreter::visit_if_node(Nodes::Node *node){
   	   if(visit(node->node_a).value>0){
   	     return Values::Number(visit(node->node_b).value);
   	   }
   	   return 0;
   	 }

   Values::Number Interpreter::visit_while_node(Nodes::Node *node){
   	   while(visit(node->node_a).value){
   	    visit(node->node_b).value;
   	   }
   	   return 0;
   	 }

    Values::Number Interpreter::visit_multiply_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value * visit(node->node_b).value);
    }
    Values::Number Interpreter::visit_divide_node(Nodes::Node *node) {
        double value = visit(node->node_b).value;

        if (value == 0.0)
            SyntaxError("Error:Number divisin/modulo by zero","");

        return Values::Number(visit(node->node_a).value / value);
    }
				
				Values::Number Interpreter::visit_modulus_node(Nodes::Node *node) {
        int value = visit(node->node_b).value;

        if (value == 0.0){
            throw std::string("Error:Number divisin/modulo by zero");}
								int other_value = visit(node->node_a).value;
        return Values::Number(other_value % value);
    }
				
    Values::Number Interpreter::visit_power_node(Nodes::Node *node) {
        return Values::Number(std::pow(visit(node->node_a).value, visit(node->node_b).value));
    }

    Values::Number Interpreter::visit_plus_node(Nodes::Node *node) {
        return visit(node->node_a);
    }

    Values::Number Interpreter::visit_and_node(Nodes::Node *node) {
     return Values::Number(visit(node->node_a).value and visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_or_node(Nodes::Node *node) {
     return Values::Number(visit(node->node_a).value or visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_not_node(Nodes::Node *node) {
     return Values::Number(not visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_minus_node(Nodes::Node *node){ 
        return Values::Number(-1 * visit(node->node_a).value);
    }
    Values::Number Interpreter::visit_var_assign_node(Nodes::Node *node){
     if(symbol.is_defined(node->name)){
    symbol.set(node->name,visit(node->node_a).value);
    return Values::Number(visit(node->node_a).value);}
    else{
      //KeywordError("invalid keyword",node->name);
      symbol.set(node->name,visit(node->node_a).value);
      return Values::Number(visit(node->node_a).value);
    }
       }
    
    Values::Number Interpreter::visit_var_access_node(Nodes::Node *node){
    	symbol.symbol["true"] = 1;
    	symbol.symbol["false"] = 0.0;
    	symbol.symbol["none"] = 0.0;
    	
   		return Values::Number(symbol.get(node->key));
   		
    }
    
				
	 Values::String Interpreter::visit_(Nodes::Node *node) {
	 	std::cout<<"1"<<std::endl;
	 	switch (node->node_type) {
      case Nodes::StringNode:
           return Values::String(node->name);
	 }
	}
}
