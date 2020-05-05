#include "Expr_Node_Visitor.h"


Div_Node::Div_Node()
{

}


Div_Node::~Div_Node()
{

}

int Div_Node::get_priority()
{
	return 2;
}
void Div_Node::accept(Expr_Node_Visitor &v)
{
	v.visit_div_node(*this);
}
