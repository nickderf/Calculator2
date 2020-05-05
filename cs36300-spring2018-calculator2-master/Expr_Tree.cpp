#include "Expr_Node.h"
#include "Expr_Tree.h"

Expr_Tree::Expr_Tree()
	:head(nullptr)
{

}

Expr_Tree::~Expr_Tree()
{

}
void Expr_Tree::set_head(Expr_Node *node)
{
	
	this->head = node;
}

Expr_Node* Expr_Tree::get_head()
{
	return this->head;
}