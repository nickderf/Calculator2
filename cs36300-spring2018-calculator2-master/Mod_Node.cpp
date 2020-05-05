#include "Expr_Node_Visitor.h"


Mod_Node::Mod_Node()
{

}


Mod_Node::~Mod_Node()
{

}

int Mod_Node::get_priority()
{
	return 2;
}
void Mod_Node::accept(Expr_Node_Visitor &v)
{
	v.visit_mod_node(*this);
}

