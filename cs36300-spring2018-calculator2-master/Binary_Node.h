#ifndef BINARY_NODE
#define BINARY_NODE

#include "Expr_Node.h"

class Binary_Node : public Expr_Node
{
public:
	Binary_Node();
	~Binary_Node();

	virtual void accept(Expr_Node_Visitor &node);
	virtual void lAccept(Expr_Node_Visitor &node);
	virtual void rAccept(Expr_Node_Visitor &node);

	//Add child to the node
	virtual void add_lChild(Expr_Node *node);
	virtual void add_rChild(Expr_Node *node);

	//Each inheriting class will have to provide its own priority
	virtual int get_priority() = 0;

protected:
	Expr_Node *left;
	Expr_Node *right;

};
#endif   // !defined BINARY_NODE