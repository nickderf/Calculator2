#ifndef MULT_NODE
#define MULT_NODE

#include "Binary_Node.h"
class Mult_Node : public Binary_Node
{
public:
	Mult_Node();
	~Mult_Node();

	virtual void accept(Expr_Node_Visitor &node);
	virtual int get_priority();
};

#endif //!define MULT_NODE