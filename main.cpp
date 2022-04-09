#include "stack.h"
#include <iostream>
#include <string>

int main() {
	Stack<int> exampleInt;
	Stack<std::string> exampleString;
	
	try{
		exampleInt.pop();
	}catch(StackException &exception){
		std::cout << exception.getExceptionName() << " " << exception.getExceptionInfo() << std::endl;
	}
	
	try{
		std::cout << exampleInt + 9;
	}catch(StackException &exception){
		std::cout << exception.getExceptionName() << " " << exception.getExceptionInfo() << std::endl;
	}

	try{
		std::cout << exampleInt;
	}catch(StackException &exception){
		std::cout << exception.getExceptionName() << " " << exception.getExceptionInfo() << std::endl;
	}

	try{
		std::cout<< exampleInt.getLength();
	}catch(StackException &exception){
		std::cout << exception.getExceptionName() << " " << exception.getExceptionInfo() << std::endl;
	}
	std::cout << std::endl;

	exampleInt.push(8);
	for(int i = 0; i < 999; i++){
		exampleInt.push(i);
	}
	exampleString.push("Something");

	exampleInt.push(-3);
	exampleString.push("Nothing");

	exampleInt.push(99999);
	exampleString.push("Anything");

	exampleInt.push(0);
	exampleString.push("");

	std::cout << "<< exampleInt is " << exampleInt << std::endl;
	std::cout << "<< exampleString is " << exampleString << std::endl << std::endl;

	std::cout << ">> exampleInt is "; std::cin >> exampleInt; std::cout << std::endl;
	std::cout << ">> exampleString is "; std::cin >> exampleString; std::cout << std::endl << std::endl;

	std::cout << "<< exampleInt is " << exampleInt << std::endl;
	std::cout << "<< exampleString is " << exampleString << std::endl;

	std::cout << "exampleInt.getLength() is " << exampleInt.getLength() << std::endl;
	std::cout << "exampleString.getLength() is " << exampleString.getLength() << std::endl << std::endl;

	std::cout << "exampleInt.getLast() is " << exampleInt.getLast() << std::endl;
	std::cout << "exampleString.getLast() is " << exampleString.getLast() << std::endl << std::endl;

	std::cout << "exampleInt.getMin() is " << exampleInt.getMin() << std::endl;
	std::cout << "exampleString.getMin() is " << exampleString.getMin() << std::endl << std::endl;

	std::cout << "exampleInt.getMax() is " << exampleInt.getMax() << std::endl;
	std::cout << "exampleString.getMax() is " << exampleString.getMax() << std::endl << std::endl;

	std::cout << "exampleInt + 6 is " << exampleInt + 6 << std::endl;
	std::cout << "exampleString + IJK is " << exampleString + "IJK" << std::endl << std::endl;

	std::cout << "exampleInt * 4 is " << exampleInt * 4 << std::endl;
	std::cout << "exampleString * 4 is " << exampleString * 4 << std::endl << std::endl;

	std::cout << "exampleInt * 0 is " << exampleInt * 0 << std::endl;
	std::cout << "exampleString * 0 is " << exampleString * 0 << std::endl << std::endl;


	std::cout << "exampleInt - 6 is " << exampleInt - 6 << std::endl;


	std::string j;
	std:: cout << "Enter something to continue ";std::cin >> j;

	Stack<int> exampleIntSecond = exampleInt;
	exampleIntSecond.pop();

	std::cout << "<< exampleIntSecond is " << exampleIntSecond << std::endl;
	std::cout << "<< exampleInt       is " << exampleInt << std::endl;


	std::cout << "exampleIntSecond.getLength() is " << exampleIntSecond.getLength() << std::endl;
	std::cout << "exampleInt.getLength()       is " << exampleInt.getLength() << std::endl;

	int k;
	std:: cout << "Enter something to exit ";std::cin >> k;

	return 0;
}