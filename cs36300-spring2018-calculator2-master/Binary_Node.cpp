#include "Binary_Node.h"

Binary_Node::Binary_Node()
	:left(nullptr),
	right(nullptr)
{

}

Binary_Node::~Binary_Node()
{

}

void Binary_Node::accept(Expr_Node_Visitor &node)
{
	
}

void Binary_Node::lAccept(Expr_Node_Visitor &node)
{
	this->left->accept(node);
}

void Binary_Node::rAccept(Expr_Node_Visitor &node)
{
	this->right->accept(node);
}
void Binary_Node::add_lChild(Expr_Node *node)
{
	this->left = node;
}

void Binary_Node::add_rChild(Expr_Node* node)
{
	this->right = node;
}