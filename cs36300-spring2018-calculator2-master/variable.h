#ifndef VARIABLE
#define VARIABLE

#include "Num_Node.h"
class variable
{
public:
	variable();
	~variable();
	
	//This version is the user inputted
	void set_value();
	
	//This version of set value can be used when you have a pre-determined number
	void set_value(int n);
	
	int get_value();
	
	void set_letter(char ch);
	char get_letter();
	
	void set_node(Num_Node &n);
	Num_Node *get_node();

private:
	//Value the user inputs
	int value;
	
	//Letter associated with the variable
	char letter;
	
	//A temporary Expr_Node that is the placeholder in the tree this will be used to fill the hole once we know 
	//what the value of the variable is
	Num_Node *node;
};

#endif //!define ADD_NODE