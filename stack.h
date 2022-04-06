#ifndef STACK_H
#define STACK_H
#include "stackException.h"
#include <string>

template <typename type>
class Stack{
	private:
		struct Element{
			Element* structPrevious;
			type structCurrent;
		};
		int length = 0;
		Element *ptrCurrentElement = nullptr;

	public:
		Stack();

		Stack(type value);

		Stack(const Stack &src);

		~Stack();

		type getMax();

		type getMin();

		type getLast();

		int getLength();

		void pop();

		void push(type newElement);
		
		type operator + (type value);
		
		type operator - (type value);

		type operator * (int value);

		friend std::ostream &operator << (std::ostream &out, Stack &stack) {
			if(!stack.length){
				throw StackException("EmptyStackException", "Trying to do '<<' with element in an empty stack");
			}
			out << stack.getLast();
			return out;
		}
		
		friend std::istream &operator >> (std::istream &in, Stack &stack) {
			if(!stack.length){
				throw StackException("EmptyStackException", "Trying to do '>>' with element in an empty stack");
			}
			in >> stack.ptrCurrentElement->structCurrent;
			return in;
		}
};

template <typename type>
Stack<type>::Stack(){}

template <typename type>
Stack<type>::Stack(type value) { 
	this->push(value); 
}

template <typename type>
Stack<type>::Stack(const Stack &src){
	length = src.length;
	if(length){
		Element *ptrToCopy = src.ptrCurrentElement;
		int j = 1;
		for(int i = 0; i < length; i++){
			for(int k = 0; k < (length - j); k++){
				switch(length - j){
					case 0: { break; }
					default: { ptrToCopy = ptrToCopy->structPrevious; }
				}
			}
			Element *current = new Element;
			current->structCurrent = ptrToCopy->structCurrent;
			current->structPrevious = ptrCurrentElement;
			ptrCurrentElement = current;
			ptrToCopy = src.ptrCurrentElement;
			j++;
		}
	}
}

template <typename type>
Stack<type>::~Stack(){
	if(length){
		Element *ptrToDelete;
		for(int i = 0; i < length; i++){
			ptrToDelete = ptrCurrentElement;
			ptrCurrentElement = ptrCurrentElement->structPrevious;
		delete ptrToDelete;
		}
	}
}

template <typename type>
type Stack<type>::getMax(){
	if(!length){
		throw StackException("EmptyStackException", "Trying to get a value in an empty stack");
	}
	Element *iter = ptrCurrentElement;
	type maxElement;
	maxElement = ptrCurrentElement->structCurrent;
	for(int i = 0; i < length; i++){
		if(iter->structCurrent > maxElement)
			maxElement = iter->structCurrent;
		iter = iter->structPrevious;
	}
	return maxElement;
}

template <typename type>
type Stack<type>::getMin(){
	if(!length){
		throw StackException("EmptyStackException", "Trying to get a value in an empty stack");
	}
	Element *iter = ptrCurrentElement;
	type minElement;
	minElement = ptrCurrentElement->structCurrent;
	for(int i = 0; i < length; i++){
		if(iter->structCurrent < minElement)
			minElement = iter->structCurrent;
		iter = iter->structPrevious;
	}
	return minElement;
}

template <typename type>
type Stack<type>::getLast() {
	if(!length){
		throw StackException("EmptyStackException", "Trying to get a value in an empty stack");
	}
	return ptrCurrentElement->structCurrent;
}

template <typename type>
int Stack<type>::getLength() {
	return length;
}

template <typename type>
void Stack<type>::pop(){
	if(!length){
		throw StackException("EmptyStackException", "Trying to pop an element in an empty stack");
	}
	Element *ptrToDelete;
	ptrToDelete = ptrCurrentElement;
	ptrCurrentElement = ptrCurrentElement->structPrevious;
	delete ptrToDelete;
	length--;
}

template <typename type>
void Stack<type>::push(type newElement){
	Element *current = new Element;
	current->structCurrent = newElement;
	current->structPrevious = ptrCurrentElement;
	ptrCurrentElement = current;
	length++;
}

template <typename type>
type Stack<type>::operator + (type value) {
	if(!length){
		throw StackException("EmptyStackException", "Trying to do '+' with element in an empty stack");
	}
	return (ptrCurrentElement->structCurrent + value);
}

template <typename type>
type Stack<type>::operator - (type value) {
	if(!length){
		throw StackException("EmptyStackException", "Trying to do '-' with element in an empty stack");
	}
	return (ptrCurrentElement->structCurrent - value);
}

template <typename type>
type Stack<type>::operator* (int value) {
	if(!length){
		throw StackException("EmptyStackException", "Trying to do '*' with element in an empty stack");
	}
	return ptrCurrentElement->structCurrent * value;
}


template <>
std::string Stack<std::string>::operator*(int value){
	if(!length){
		throw StackException("EmptyStackException", "Trying to do '*' with element in an empty stack");
	} else if(!value){
		return "";
	} else if(value < 0){
		throw StackException("NegativeStringMultiplicationException", "Trying to do '*' with std::string element with negative number");
	}
	std::string temp;
	for(int i = 0; i < abs(value); i++){
		temp += ptrCurrentElement->structCurrent;
	}
	return temp;	
}

#endif