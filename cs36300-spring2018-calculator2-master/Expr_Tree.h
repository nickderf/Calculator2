#ifndef EXPR_TREE
#define EXPR_TREE

#include "Expr_Node.h"
class Expr_Tree
{
public:
	Expr_Tree();
	~Expr_Tree();

	void set_head(Expr_Node* node);
	Expr_Node* get_head();

private:
	Expr_Node * head;

};

#endif //!define EXPR_TREE

