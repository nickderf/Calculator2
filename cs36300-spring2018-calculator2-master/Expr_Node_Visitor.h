#ifndef EXPR_NODE_VISITOR
#define EXPR_NODE_VISITOR

#include "Add_Node.h"
#include "Sub_Node.h"
#include "Mult_Node.h"
#include "Div_Node.h"
#include "Mod_Node.h"
#include "Num_Node.h"

class Expr_Node_Visitor
{
public: 
	virtual void visit_add_node(Add_Node &node) = 0;
	virtual void visit_sub_node(Sub_Node &node) = 0;
	virtual void visit_mult_node(Mult_Node &node) = 0;
	virtual void visit_div_node(Div_Node &node) = 0;
	virtual void visit_mod_node(Mod_Node &node) = 0;
	virtual void visit_num_node(Num_Node &node) = 0;
};

#endif //!define EXPR_NODE_VISITOR