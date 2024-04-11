#include <iostream>
#include <cstdlib>
#include <iostream>
#include "MyStack.hpp"

using namespace std;

MyStack::MyStack()
{
	head = NULL;
}

MyStack::~MyStack()
{
	Node* current = head;
	Node* next;
	while(current != nullptr){
		next = current -> next;
		delete current;
		current = next;
	}
}

bool MyStack::isEmpty()
{
	if(head == nullptr){
		return true;
	}
	return false;
}

void MyStack::push(int val)
{
	Node* node = new Node();
	node -> next = head;
	node -> val = val;
	head = node;

}

void MyStack::pop()
{   
	if(isEmpty()){
		cout<<"Stack empty, cannot pop an item!"<<endl;
		return;
	}else{
	Node* temp = head;
	head = head->next;
	delete temp;
	}

}

Node* MyStack::peek()
{
	if(isEmpty()){
		cout << "Stack empty, cannot peek!" << endl;
		return NULL;
	}
	return head;
}
