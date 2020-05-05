#ifndef EVAL_TREE
#define EVAL_TREE

#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree :public Expr_Node_Visitor
{
public:
	Eval_Expr_Tree();
	~Eval_Expr_Tree();

	virtual void visit_add_node(Add_Node &node);
	virtual void visit_sub_node(Sub_Node &node);
	virtual void visit_mult_node(Mult_Node &node);
	virtual void visit_div_node(Div_Node &node);
	virtual void visit_mod_node(Mod_Node &node);
	virtual void visit_num_node(Num_Node &node);
	
	int get_result();

private:

	int result;

	int temp_num;

	//Stores values for left and right children of a node
	Expr_Node *cur_left;
	Expr_Node *cur_right;
	//Temporarily stores a node, while it is being placed in the correct place (cur_left or cur_right)
	Num_Node *temp_node;
};



#endif //!define EVAL_TREE