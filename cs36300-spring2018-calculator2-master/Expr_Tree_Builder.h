	#ifndef EXPR_TREE_BUILDER
#define EXPR_TREE_BUILDER

#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "Expr_Node.h"
#include "Stack.h"
#include "variable.h"

class Expr_Tree_Builder :public Expr_Builder
{
public:
	Expr_Tree_Builder();
	virtual ~Expr_Tree_Builder();

	virtual void start_expression();
	virtual Expr_Tree * get_expression();

	//Handles logic when pushing an operator to the operator stack
	void push_op(Binary_Node* n);

	//Handles logic when popping an operator from the op stack
	void pop_op();

	//This handles when an operator is popped from the operator stack
	virtual void handle_node(Binary_Node* node);

	//Empties the rest of the stacks at the end of an expression and handles them accordingly
	void empty_op_stack();

	//Method to push to the child_stack
	void push_to_child(Expr_Node * n);

	virtual void build_number(int n);
	
	//This builds a number node, since it is after the construction of the tree, it doesn't need to do what a regular build number does
	virtual void build_var_number(variable* v);
	
	virtual void build_add();
	virtual void build_sub();
	virtual void build_mult();
	virtual void build_div();
	virtual void build_mod();
	virtual variable* build_var(char ch);

private:
	Expr_Tree * tree;
	//Stack for operators
	Stack <Binary_Node *> op_stack;

	//Stack for all children nodes that will be added to a parent node (Number nodes and root operator nodes that are becoming children)
	Stack <Expr_Node *> child_stack;

};

#endif   // !defined EXPR_TREE_BUILDER