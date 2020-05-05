#ifndef ADD_NODE
#define ADD_NODE

#include "Binary_Node.h"

class Add_Node : public Binary_Node
{
public:
	Add_Node();
	~Add_Node();

	virtual void accept(Expr_Node_Visitor &node);
	virtual int get_priority();

};

#endif //!define ADD_NODE