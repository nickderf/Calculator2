#ifndef SUB_NODE
#define SUB_NODE

#include "Binary_Node.h"
class Sub_Node : public Binary_Node
{
public:
	Sub_Node();
	~Sub_Node();

	virtual void accept(Expr_Node_Visitor &node);
	virtual int get_priority();
};

#endif //!define SUB_NODE