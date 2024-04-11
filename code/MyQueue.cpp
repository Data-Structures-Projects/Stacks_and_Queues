#include "MyQueue.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

MyQueue::MyQueue(){
	char queue[SIZE];
    queueFront = -1;
	queueEnd = -1;
}

bool MyQueue::isEmpty(){
	if(queueFront == -1){
		return true;
	}
    return false;
}

bool MyQueue::isFull(){
	if(queueSize() == SIZE){
		return true;
	}
    return false;
}

void MyQueue::enqueue(char ch){
	if(isFull()){
		cout << "Queue full, cannot add!" << endl;
		return;
	}
	if(isEmpty()){
		queueFront = 0;
		queueEnd = 0;
		queue[queueEnd] = ch;
		return;
	}
	queueEnd++;
	queueEnd = queueEnd % SIZE;
	queue[queueEnd] = ch;
	
}


void MyQueue::dequeue(){
	if(isEmpty()){
		cout << "Queue empty, cannot dequeue!" << endl;
		return;
	}
	if(queueFront == queueEnd){
		queue[queueFront] = '\0';
		queueEnd = -1;
		queueFront = -1;
		return;
	}
	queue[queueFront] = '\0';
	queueFront++;
	queueFront = queueFront % SIZE;
	
}


char MyQueue::peek(){
	if(isEmpty()){
		cout<<"Queue empty, cannot peek!" << endl;
		return '\0';
	}
	return queue[(queueFront)%SIZE];
}

int MyQueue::queueSize(){
	if(isEmpty()){
		return 0;
	}
	if(queueEnd < queueFront){
		return 20-queueFront + queueEnd + 1;
	}
    return queueEnd - queueFront + 1;
}
