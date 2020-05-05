#ifndef EXPR_NODE
#define EXPR_NODE

class Expr_Node_Visitor;

class Expr_Node
{
public:

	virtual void accept(Expr_Node_Visitor &node) = 0;

	virtual int get_priority() = 0;

	

};

#endif   // !defined EXPR_NODE