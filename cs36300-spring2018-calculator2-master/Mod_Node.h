#ifndef MOD_NODE
#define MOD_NODE

#include "Binary_Node.h"
class Mod_Node : public Binary_Node
{
public:
	Mod_Node();
	~Mod_Node();

	virtual void accept(Expr_Node_Visitor &node);
	virtual int get_priority();

};

#endif //!define MOD_NODE