#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include "Array.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"
#include "variable.h"
class Calculator
{
public:
	Calculator();

	~Calculator();

	//Parse the expression that user input
	void parse_expression(std::string infix);

	//Use the expression that is in postfix notation to create a binary tree
	void build_tree();

	//Specific logic for building tree
	Expr_Node* construction(Expr_Tree_Builder* b);

	//Evaluate the math expression
	void evaluate();

	//Return the calculated result after expression is evaluated
	int get_result();
	
	//Sort in alpha order
	void sort_variable();
	
	//Swap two concsecutive variables in the var_array. Pass the current position we are in
	void swap_var(int cur_pos);

	//Iterate through the variable array and collect the value for each variable. Each variable's value is only collected once
	//duplicates receive the same value as previous.
	void get_var_values();
	
	//Iterate through the variable array and replace each variable array's 
	void switchout_variables();
	
private:

	Expr_Tree_Builder *builder;
	
	Expr_Tree * tree_;
	
	Eval_Expr_Tree *visitor;

	//Array to store the parsed expression
	Array<std::string> chArr;

	//Counter for where we are in the chArr array
	int chArr_counter;

	//Array to store our expressions/builders. These are separated because of parenthesis.
	//Each pair of parens has its own express/builder
	Array<Expr_Tree_Builder *> builder_array;

	//Value that holds the current position being worked on in the builder array
	//This is set to 1, because the whole expression is put into the array first
	int builder_counter;

	//Stores the current position that we are working in
	int var_array_pos;

	//Stores variable objects temporarily while we wait to sort and get their values
	Array<variable *>var_array;
};

#endif   // !defined CALCULATOR_H