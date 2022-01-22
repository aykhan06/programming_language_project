#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

#include "nodes.h"
#include "values.h"

namespace Interpreter {
	 class Interpreter {
   public:
    Values::Number visit(Nodes::Node *);
    
    Values::String visit_(Nodes::Node *);
   
    Values::Number visit_add_node(Nodes::Node *);
    
    Values::Number visit_subtract_node(Nodes::Node *);
    
    Values::Number visit_multiply_node(Nodes::Node *);
    
    Values::Number visit_divide_node(Nodes::Node *);
    
    Values::Number visit_power_node(Nodes::Node *);
    
    Values::Number visit_plus_node(Nodes::Node *);
    
    Values::Number visit_minus_node(Nodes::Node *);
    
    Values::Number visit_modulus_node(Nodes::Node *);
    
    Values::Number visit_ee_node(Nodes::Node *);
    
    Values::Number visit_ne_node(Nodes::Node *);
    
    Values::Number visit_gt_node(Nodes::Node *);
    
    Values::Number visit_lt_node(Nodes::Node *);
    
    Values::Number visit_gte_node(Nodes::Node *);
    
    Values::Number visit_lte_node(Nodes::Node *);
    
    Values::Number visit_var_access_node(Nodes::Node *);
    
    Values::Number visit_var_assign_node(Nodes::Node *);
    
    Values::Number visit_delete_node(Nodes::Node *);
    
    Values::Number visit_func_def_node(Nodes::Node *);
    
    Values::Number visit_and_node(Nodes::Node *);
    
    Values::Number visit_or_node(Nodes::Node *);
    
    Values::Number visit_not_node(Nodes::Node *);
    
    Values::Number visit_if_node(Nodes::Node *);
    
    Values::Number visit_while_node(Nodes::Node *);
    };

}

#endif // INTERPRETER_H
