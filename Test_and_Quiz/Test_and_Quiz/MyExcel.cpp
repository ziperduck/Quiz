#include "MyExcel.h"


MyStack::MyNode::MyNode(MyNode* next,const int num) : NextStack(next), data(num)
{
}

MyStack::MyNode::~MyNode()
{
}

MyStack::MyStack() : statsize(1),Start(MyNode(NULL, 0)),current(&Start)
{
}

MyStack::~MyStack()
{
	if (current != &Start)
		remove();
}


void MyStack::pushi(const int num){
	MyNode* mn = new MyNode(current, num);
	current = mn;
}

void MyStack::pop() {

	if (current == &Start) 
		return;

	MyNode* detroyd = current;
	current = current->NextStack;

	delete detroyd;
}

int MyStack::peek()const{
	return current->data;
}

void MyStack::remove() {

	while (&Start != current)
	{
		MyNode* detroyd = current;
		current = current->NextStack;

		delete detroyd;
	}
}

