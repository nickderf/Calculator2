#include "variable.h"

#include <iostream>
variable::variable()
{

}

variable:: ~variable()
{
	
}

void variable::set_value()
{
	std::cout<<"Enter the value of "<<this->letter<<": ";
	std::cin>>this->value;
}

void variable::set_value(int n)
{
	this->value = n;
}
int variable::get_value()
{
	
	return this->value;
}

void variable::set_letter(char ch)
{
	this->letter = ch;
}

char variable::get_letter()
{
	return this->letter;
}

void variable::set_node(Num_Node &n)
{
	this->node = &n;
}

Num_Node *variable::get_node()
{
	return this->node;
}