#pragma once
#include <iostream>
#include <string>

class MyStack
{
public:
	class MyNode
	{
	public:
		MyNode(MyNode* next = NULL,const int num = 0);
		~MyNode();

		int data;

		MyNode* NextStack;
	};

	MyStack();
	~MyStack();

	void pushi(const int num);

	void pop();

	int peek()const;

	void remove();
private:


	MyNode* current;

	MyNode Start;

	int statsize;

};

