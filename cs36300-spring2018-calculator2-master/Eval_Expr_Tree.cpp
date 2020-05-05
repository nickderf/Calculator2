#include "Eval_Expr_Tree.h"
#include <iostream>
Eval_Expr_Tree::Eval_Expr_Tree()
	:cur_left(nullptr),
	cur_right(nullptr)
{

}

Eval_Expr_Tree::~Eval_Expr_Tree()
{

}


void Eval_Expr_Tree::visit_add_node(Add_Node &node)
{
  // COMMENT You implementation of the visitor pattern is way more complex
  // than it needs to be. You are creating temp number node to store the
  // result. Why not just store the actual result in an interger? This way,
  // you do not have this unnecessary allocation of a number class just to
  // wrap a number.

	//Stores values for left and right children of a node
	//Copied code. I want to try and abstract this portion for it to still work with all the methods.
	int cur_left;
	int cur_right;

	node.lAccept(*this);
	cur_left = this->temp_num;
	node.rAccept(*this);
	cur_right = this->temp_num;

	this->result = cur_left + cur_right;
	this->temp_num = this->result;
}

void Eval_Expr_Tree::visit_sub_node(Sub_Node &node)
{
  // COMMENT You implementation of the visitor pattern is way more complex
  // than it needs to be. You are creating temp number node to store the
  // result. Why not just store the actual result in an interger? This way,
  // you do not have this unnecessary allocation of a number class just to
  // wrap a number.

	//Changed from using nodes to store results to integers
  
	//Stores values for left and right children of a node
	int cur_left;
	int cur_right;

	node.lAccept(*this);
	cur_left = this->temp_num;
	node.rAccept(*this);
	cur_right = this->temp_num;

	this->result = cur_left - cur_right;
	this->temp_num = this->result;

}

void Eval_Expr_Tree::visit_mult_node(Mult_Node &node)
{
  // COMMENT You implementation of the visitor pattern is way more complex
  // than it needs to be. You are creating temp number node to store the
  // result. Why not just store the actual result in an interger? This way,
  // you do not have this unnecessary allocation of a number class just to
  // wrap a number.

  //Changed from using nodes to store results to integers

//Stores values for left and right children of a node
	int cur_left;
	int cur_right;

	node.lAccept(*this);
	cur_left = this->temp_num;
	node.rAccept(*this);
	cur_right = this->temp_num;

	this->result = cur_left * cur_right;
	this->temp_num = this->result;
}

void Eval_Expr_Tree::visit_div_node(Div_Node &node)
{
  // COMMENT You implementation of the visitor pattern is way more complex
  // than it needs to be. You are creating temp number node to store the
  // result. Why not just store the actual result in an interger? This way,
  // you do not have this unnecessary allocation of a number class just to
  // wrap a number.

  //Changed from using nodes to store results to integers

//Stores values for left and right children of a node
	int cur_left;
	int cur_right;

	node.lAccept(*this);
	cur_left = this->temp_num;
	node.rAccept(*this);
	cur_right = this->temp_num;

	this->result = cur_left / cur_right;
	this->temp_num = this->result;
}

void Eval_Expr_Tree::visit_mod_node(Mod_Node &node)
{
  // COMMENT You implementation of the visitor pattern is way more complex
  // than it needs to be. You are creating temp number node to store the
  // result. Why not just store the actual result in an interger? This way,
  // you do not have this unnecessary allocation of a number class just to
  // wrap a number.

  //Changed from using nodes to store results to integers

//Stores values for left and right children of a node
	int cur_left;
	int cur_right;

	node.lAccept(*this);
	cur_left = this->temp_num;
	node.rAccept(*this);
	cur_right = this->temp_num;

	this->result = cur_left % cur_right;
	this->temp_num = this->result;
}

void Eval_Expr_Tree::visit_num_node(Num_Node &node)
{
  // COMMENT Why not just store the value in the node in a integer result
  // parameter?!

  //Changed from using nodes to store results to integers
  
	this->temp_num = node.get_value();
}

int Eval_Expr_Tree::get_result()
{
	return this->result;


}
