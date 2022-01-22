#include <iostream>
#include <string>
#include <sstream>
#include "nodes.h"
using namespace std;
namespace Nodes {
    Node::Node(NodeType node_type, double value) {
        this->node_type = node_type;
        this->value = value;
        node_a = NULL;
        node_b = NULL;
    }

    Node::Node(NodeType node_type,Nodes::Node*,double value) {
        this->node_type = node_type;
        this->value = value;
        node_a = NULL;
        node_b = NULL;
    }

    Node::Node(NodeType node_type, Node *node_a, Node *node_b) {
        this->node_type = node_type;
        this->node_a = node_a;
        this->node_b = node_b;
    }

    Node::Node(NodeType node_type) {
        this->node_type = node_type;
        node_a = NULL;
        node_b = NULL;
    }

    Node::Node(NodeType node_type,std::string key) {
        this->node_type = node_type;
        this->key = key;
        node_a = NULL;
        node_b = NULL;
    }

    Node::Node(NodeType node_type, Node *node_a) {
        this->node_type = node_type;
        this->node_a = node_a;
        node_b = NULL;
    }

    Node::Node(NodeType node_type, Node *node_a,std::string name) {
        this->node_type = node_type;
        this->node_a = node_a;
        this->name = name;
        node_b = NULL;
    }

    Node::operator std::string const() {
    		std::stringstream ss;
    		ss>>value;
        switch (node_type) {
            case NumberNode: return ss.str();
            case PlusNode: return "(+" + static_cast<std::string>(*node_a) + ")";
            case MinusNode: return "(-" + static_cast<std::string>(*node_a) + ")";
            case AddNode: return "(" + static_cast<std::string>(*node_a) + " + " + static_cast<std::string>(*node_b) + ")";
            case SubtractNode: return "(" + static_cast<std::string>(*node_a) + " - " + static_cast<std::string>(*node_b) + ")";
            case MultiplyNode: return "(" + static_cast<std::string>(*node_a) + " * " + static_cast<std::string>(*node_b) + ")";
            case DivideNode: return "(" + static_cast<std::string>(*node_a) + " / " + static_cast<std::string>(*node_b) + ")";
            case PowerNode: return "(" + static_cast<std::string>(*node_a) + " ** " + static_cast<std::string>(*node_b) + ")";
            case EENode: return "(" + static_cast<std::string>(*node_a) + " == " + static_cast<std::string>(*node_b) + ")";
       					case NENode: return "(" + static_cast<std::string>(*node_a) + " != " + static_cast<std::string>(*node_b) + ")";
            case GTNode: return "(" + static_cast<std::string>(*node_a) + " > " + static_cast<std::string>(*node_b) + ")";
            case LTNode: return "(" + static_cast<std::string>(*node_a) + " < " + static_cast<std::string>(*node_b) + ")";
            case LTENode: return "(" + static_cast<std::string>(*node_a) + " >= " + static_cast<std::string>(*node_b) + ")";
            case GTENode: return "(" + static_cast<std::string>(*node_a) + " <= " + static_cast<std::string>(*node_b) + ")";
            default: return "()";
        }
    }

    void print_node(Node *node) {
        std::cout << static_cast<std::string>(*node) << '\n';
    }

    void free_node(Node *node) {
        if (node->node_a != NULL) {
            free_node(node->node_a);
            node->node_a = NULL;
        }

        if (node->node_b != NULL) {
            free_node(node->node_b);
            node->node_b = NULL;
        }

        delete node;
    }
}
