#include "Expr_Tree_Builder.h"

#include "variable.h"
Expr_Tree_Builder::Expr_Tree_Builder()
{

}

Expr_Tree_Builder::~Expr_Tree_Builder()
{
	delete this->tree;
}

void Expr_Tree_Builder::start_expression()
{
	this->tree = new Expr_Tree();
}

Expr_Tree* Expr_Tree_Builder::get_expression()
{
	return this->tree;
}

void Expr_Tree_Builder::push_op(Binary_Node* n)
{

	while (!this->op_stack.is_empty() && n->get_priority() < this->op_stack.top()->get_priority())
	{
		this->pop_op();
	}
	
	this->op_stack.push(n);
}

void Expr_Tree_Builder::pop_op()
{
	this->handle_node(this->op_stack.pop());

}

void Expr_Tree_Builder::handle_node(Binary_Node *node)
{
	//Set the head of our expression tree to this current node. Will continually be changed until we reach the final node (real head)
	this->tree->set_head(node);
	node->add_rChild(this->child_stack.pop());
	node->add_lChild(this->child_stack.pop());

	this->child_stack.push(node);
}

void Expr_Tree_Builder::empty_op_stack()
{
	while (!this->op_stack.is_empty())
	{
		this->pop_op();
	}
}

void Expr_Tree_Builder::build_number(int n)
{
	Expr_Node *node = new Num_Node(n);
	this->child_stack.push(node);
}

void Expr_Tree_Builder::build_var_number(variable* v)
{
	Expr_Node *x = (v->get_node());
	Num_Node *n = new Num_Node(v->get_value());
	x = n;
	v->get_node()->set_value(v->get_value());
}

void Expr_Tree_Builder::build_add()
{
	Binary_Node * node = new Add_Node();
	Expr_Node * n = node;

	this->push_op(node);
	
}

void Expr_Tree_Builder::build_sub()
{
	Binary_Node * node = new Sub_Node();
	Expr_Node * n = node;

	this->push_op(node);
	
}

void Expr_Tree_Builder::build_mult()
{
	Binary_Node * node = new Mult_Node();
	Expr_Node * n = node
		;
	this->push_op(node);
	
}

void Expr_Tree_Builder::build_div()	
{
	Binary_Node * node = new Div_Node();
	Expr_Node * n = node;

	this->push_op(node);
	
}

void Expr_Tree_Builder::build_mod()
{
	Binary_Node * node = new Mod_Node();
	Expr_Node * n = node;

	this->push_op(node);
	
}


variable * Expr_Tree_Builder::build_var(char ch)
{
	//Create a placeholder number node with value 0 to put into the tree structure
	Num_Node *node = new Num_Node(0);
	this->child_stack.push(node);
	
	variable *v = new variable();
	v->set_node(*node);
	v->set_letter(ch);
	return v;
}

void Expr_Tree_Builder::push_to_child(Expr_Node *n)
{
	this->child_stack.push(n);
	this->tree->set_head(n);
}