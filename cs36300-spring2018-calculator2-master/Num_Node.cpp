#include "Num_Node.h"
#include "Expr_Node_Visitor.h"

Num_Node::Num_Node()
	:value(0)
{

}

Num_Node::Num_Node(int n)
	:value(n)
{

}

Num_Node::~Num_Node()
{
	
}

int Num_Node::get_priority()
{
	return 0;
}

void Num_Node::accept(Expr_Node_Visitor &v)
{
	v.visit_num_node(*this);
}

int Num_Node::get_value()
{
	return this->value;
}

void Num_Node::set_value(int n)
{
	this->value = n;
}