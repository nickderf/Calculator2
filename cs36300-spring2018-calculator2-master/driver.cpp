
#include "Array.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include "Calculator.h"


int main()
{
	int go = 0;
	while (go == 0)
	{
		Calculator calc;

		std::string infix;
		std::cout << "Enter an expression: ";
		std::getline(std::cin, infix);

		calc.parse_expression(infix);
		calc.build_tree();
		calc.evaluate();

		int result = calc.get_result();
		
		std::cout<<"Your answer is: "<<result<<std::endl;
		std::string x; 

		std::getline(std::cin, x);
		if (x == "QUIT")
		{
			go = 1;
		}
	}
	return 0;
}