#ifndef EXPR_BUILDER
#define EXPR_BUILDER

#include "Add_Node.h"
#include "Sub_Node.h"
#include "Mult_Node.h"
#include "Div_Node.h"
#include "Mod_Node.h"
#include "Num_Node.h"
#include "Expr_Tree.h"
#include "variable.h"
class Expr_Builder
{
public:
	
	virtual void start_expression() = 0;
	virtual Expr_Tree* get_expression() = 0;

	virtual void build_number(int n) = 0;
	virtual void build_add() = 0;
	virtual void build_sub() = 0;
	virtual void build_mult() = 0;
	virtual void build_div() = 0;
	virtual void build_mod() = 0;
	virtual variable* build_var(char ch) = 0;

};



#endif   // !defined EXPR_BUILDER