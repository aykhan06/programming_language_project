#ifndef NODES_H
#define NODES_H

#include <string>

namespace Nodes {
  enum NodeType {
	  PlusNode,
	  MinusNode,
	  EmptyNode,
	  NumberNode,
	  FuncDefNode,
	  CallNode,
	  AddNode,
	  SubtractNode,
	  MultiplyNode,
	  DivideNode,
	  PowerNode,
	  ModulusNode,
	  EENode,
	  NENode,
	  GTNode,
	  LTNode,
	  GTENode,
	  LTENode,
	  StringNode,
	  VarAccessNode,
	  VarAssignNode,
	  AndNode,
	  OrNode,
	  NotNode,
	  IfNode,
	  WhileNode
  };

  class Node {
	  public:
    NodeType node_type;
    double value;
    Node *node_a,*node_b;
    std::string name,key;
    
    
    Node(NodeType, double value);
    Node(NodeType,Nodes::Node* ,double value);
    Node(NodeType,std::string,double value);
    Node(NodeType, Node *, Node *);
    Node(NodeType);
    Node(NodeType,std::string);
    Node(NodeType, Node *);
				Node(NodeType, Node *,std::string);
    operator std::string const();
  };

  void print_node(Node *);
  void free_node(Node *);
}

#endif // NODES_H
