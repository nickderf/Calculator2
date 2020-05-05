#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <cctype>
Calculator::Calculator()
	:builder(new Expr_Tree_Builder()),
	visitor(new Eval_Expr_Tree()),
	var_array_pos(0),
	builder_counter(1),
	chArr_counter(0)
	
	

{

}

Calculator::~Calculator()
{

}

void Calculator::parse_expression(std::string infix)
{
	//Create a stringstream object 
	std::istringstream input(infix);
	std::string token;
	
	//Make sure the array has enough space the expression
	this->chArr.resize(infix.size());

	//Counter that counts how many elements are in the array
	int size = 0;

	//Iterate through our expression, parsing it and placing each character into a char array.
	while (!input.eof())
	{
		input >> token;
		this->chArr.set(size, token);
		size++;
	}


	//Resize the array again so it's current size represents the amoutn of elements in the array
	this->chArr.resize(size);

  // COMMENT: Do not go from infix to postfix then to tree. Instead,
  // go directly from infix to tree. The extra step is not necessary.

  //I reworked the creation of the tree

	
}

Expr_Node* Calculator::construction(Expr_Tree_Builder *build)
{
	char ch;
	for (; this->chArr_counter<this->chArr.size(); this->chArr_counter++)
	{
		ch = (this->chArr.get(this->chArr_counter))[0];
		if (this->chArr.get(this->chArr_counter) == "(")
		{

			Expr_Tree_Builder *b = new Expr_Tree_Builder();
			
			this->builder_array.set(builder_counter, b);
			
			this->builder_counter++;

			b->start_expression();
			
			this->chArr_counter++;
			build->push_to_child(this->construction(b));
		}
		else if (this->chArr.get(this->chArr_counter) == ")")
		{

			build->empty_op_stack();

			this->builder_counter--;
			

			return build->get_expression()->get_head();

		}
		else if (this->chArr.get(this->chArr_counter) == "[")
		{


			Expr_Tree_Builder *b = new Expr_Tree_Builder();

			this->builder_array.set(builder_counter, b);

			this->builder_counter++;

			b->start_expression();

			this->chArr_counter++;
			Expr_Node *head = this->construction(b);
			build->push_to_child(head);
			
		}
		else if (this->chArr.get(this->chArr_counter) == "]")
		{

			build->empty_op_stack();

			this->builder_counter--;


			return build->get_expression()->get_head();

		}
		else if (this->chArr.get(this->chArr_counter) == "+")
		{
			build->build_add();
		}
		else if (this->chArr.get(this->chArr_counter) == "-")
		{
			build->build_sub();
		}
		else if (this->chArr.get(this->chArr_counter) == "*")
		{

			build->build_mult();
		}
		else if (this->chArr.get(this->chArr_counter) == "/")
		{

			build->build_div();
		}
		else if (this->chArr.get(this->chArr_counter) == "%")
		{

			build->build_mod();
		}

		//if it's a letter then create a temporary variable and put it into the variable array for further manipulation
		else if (isalpha(ch))
		{
			this->var_array.set(this->var_array_pos, build->build_var(ch));
			this->var_array_pos++;
		}
		else //if it's a number
		{
			int value = atoi(chArr.get(this->chArr_counter).c_str());

			build->build_number(value);
		}

	}

	//If there were any variables in the expression..
	if (this->var_array_pos > 0)
	{
		//If there was only one variable then we don't need to sort it
		if (this->var_array_pos > 1)
		{
			this->sort_variable();
		}
		get_var_values();

	}
	build->empty_op_stack();
}

void Calculator::build_tree()
{


	this->builder->start_expression();

	this->builder_array.resize(this->chArr.size());
	this->builder_array.set(0, this->builder);

	this->construction(this->builder);

	this->tree_ = this->builder->get_expression();

// COMMENT Per our discussion for assignment 3, you should move the
// logic in isOperator() and priority() to their corresponding concrete
// nodes.

	//I reworked a lot of my code, so this was addressed in the rework
}

void Calculator::evaluate()
{
	if (this->tree_->get_head() == nullptr)
	{
		std::cout << "Expression is invalid" << std::endl;
	}
	else
	{

		this->tree_->get_head()->accept(*this->visitor);
	}
	
}

void Calculator::sort_variable()
{
	int lett_value;
	int compared_letter_value;
	char lett;
	char compared_letter;
	for (int i = 0; i < this->var_array_pos - 1; i++)
	{
		//Assign temp char to lett, and then convert that char to its ASCII int value
		lett = this->var_array[i]->get_letter();
		lett_value = lett;
		
		//Do the same for the next variable in the array
		compared_letter = this->var_array[i + 1]->get_letter();
		compared_letter_value = compared_letter;
		
		//Sort variables
		
		if(lett_value>compared_letter_value)
		{
			this->swap_var(i);
		}
	}
	int out_of_order = 0;
	
	for (int i = 0; i < this->var_array_pos - 1; i++)
	{
		//Assign temp char to lett, and then convert that char to its ASCII int value
		lett = this->var_array[i]->get_letter();
		lett_value = lett;
		
		//Do the same for the next variable in the array
		compared_letter = this->var_array[i + 1]->get_letter();
		compared_letter_value = compared_letter;
		
		//Sort variables
		
		if(lett_value>compared_letter_value)
		{
		
			out_of_order ++;
		}
	}
	
	if(out_of_order > 0)
	{
		sort_variable();
	}
}

void Calculator::swap_var(int cur_pos)
{
	variable * temp = this->var_array[cur_pos];
	this->var_array[cur_pos] = var_array[cur_pos + 1];
	this->var_array[cur_pos + 1] = temp;
}

void Calculator::get_var_values()
{
	//Ask for the user's input for what each variable is
	
	//this array temporarily stores which variables we are using in our current expression
	Array <variable*> var_arr(this->var_array_pos);//var_array_pos is now used as the amount of elements in the var_array
	
	//Position in the temp array storing variables and their inputs
	int arr_pos = 0;
	
	for (int i = 0; i < this->var_array_pos; i++)
	{
		//when dont_set is 0 this means that the current variable we are working with is the first iteration of the variable
		int dont_set = 0;
		
		//iterate through temp variable array to see if we have already set a value for this variable
		for(int j = 0; j < arr_pos; j++)
		{
			if(this->var_array[i]->get_letter() == var_arr[j]->get_letter())
			{
				this->var_array[i]->set_value(var_arr[j]->get_value());
				dont_set++;
			}
		}
		
		if(dont_set == 0 )
		{
			this->var_array[i]->set_value();
			var_arr.set(arr_pos,this->var_array[i]);
			arr_pos++;
		}
		
		
	}
	
	this->switchout_variables();
}

void Calculator::switchout_variables()
{
	for(int i = 0; i< this->var_array_pos; i++)
	{
		this->builder->build_var_number(this->var_array.get(i));
	}
}

int Calculator::get_result()
{
	return this->visitor->get_result();
}
