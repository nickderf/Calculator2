#ifndef DIV_NODE
#define DIV_NODE

#include "Binary_Node.h"
class Div_Node : public Binary_Node
{
public:
	Div_Node();
	~Div_Node();
	
	virtual void accept(Expr_Node_Visitor &node);
	virtual int get_priority();
};

#endif //!define DIV_NODE