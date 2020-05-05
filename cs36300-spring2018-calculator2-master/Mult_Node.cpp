#include "Expr_Node_Visitor.h"


Mult_Node::Mult_Node()
{

}

Mult_Node::~Mult_Node()
{

}

int Mult_Node::get_priority()
{
	return 2;
}
void Mult_Node::accept(Expr_Node_Visitor &v)
{
	v.visit_mult_node(*this);
}
