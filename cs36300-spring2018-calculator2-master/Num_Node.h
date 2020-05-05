#ifndef NUM_NODE
#define NUM_NODE

#include "Expr_Node.h"
class Num_Node : public Expr_Node
{
public:
	Num_Node();
	Num_Node(int n);
	~Num_Node();
	
	int get_value();
	void set_value(int n);

	virtual void accept(Expr_Node_Visitor &node);

	//Priority for any number will be 0, just in case there's a situation where we need to compare priorities
	virtual int get_priority();

private:
	int value;
};

#endif //!define NUM_NODE