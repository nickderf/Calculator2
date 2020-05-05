#include "Expr_Node_Visitor.h"


Add_Node::Add_Node()
{

}


Add_Node::~Add_Node()
{

}

int Add_Node::get_priority()
{
	return 1;
}

void Add_Node::accept(Expr_Node_Visitor &v)
{
	v.visit_add_node(*this);
}

