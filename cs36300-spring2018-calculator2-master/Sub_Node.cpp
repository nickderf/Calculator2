#include "Expr_Node_Visitor.h"


Sub_Node::Sub_Node()
{

}


Sub_Node::~Sub_Node()
{

}

int Sub_Node::get_priority()
{
	return 1;
}
void Sub_Node::accept(Expr_Node_Visitor &v)
{
	v.visit_sub_node(*this);
}
