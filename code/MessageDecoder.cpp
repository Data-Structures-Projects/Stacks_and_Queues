#include <iostream>
#include <cstdlib>
#include "MessageDecoder.hpp"

using namespace std;
# define SIZE 50

MessageDecoder::MessageDecoder()
{
	my_queue = new MyQueue();
	my_stack = new MyStack();
}

MessageDecoder::~MessageDecoder()
{
	
}

/*
    generate_operator_queue(string jumbled_str)

    Takes the jumbled string as the input parameter and stores all the allowed operators in my_queue
*/
void MessageDecoder::generate_operator_queue(std::string jumbled_str){
    for(int i = 0; i < static_cast<int>(jumbled_str.size()); i++){
        if(char(jumbled_str[i]) == '+' || char(jumbled_str[i]) == '-' || char(jumbled_str[i]) == '*'){
            my_queue->enqueue(char(jumbled_str[i]));
        }
    }
}

/*
    generate_postfix(string jumbled_str)

    Takes the jumbled string as the input parameter and computes a postfix expression using the populated my_queue
    returns a postfix expression
*/
string MessageDecoder::generate_postfix(std::string jumbled_str){
    //TODO
	string postfix = "";
    int count = 0;
    for(int i = 0; i < static_cast<int>(jumbled_str.size()); i++){
        if(jumbled_str[i]>='0' && jumbled_str[i]<='9'){
            postfix = postfix + jumbled_str[i];
            count++;
            if(count == 2 && !my_queue->isEmpty()){
                postfix = postfix + my_queue->peek();
                my_queue->dequeue();
                count = 0;
            }

        }
    }
    while(!my_queue -> isEmpty()){
        postfix = postfix + my_queue -> peek();
        my_queue -> dequeue();
    }
    return postfix;
}

/* 
    evaluate_postfix(string postfix) 

    Takes the post fix string as an input parameter and evaluates the post fix string. 
    returns an integer after evaluating the postfix expression
*/

int MessageDecoder::evaluate_postfix(std::string postfix){
    int val_one;
    int val_two;
    char op;
    for(int i=0; i <static_cast<int>(postfix.size()); i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            my_stack->push(postfix[i]- '0');
        }else{
            if(postfix[i] == '+'){
                val_one = my_stack->peek()->val;
                my_stack->pop();
                val_two = my_stack->peek()->val;
                my_stack->pop();
                my_stack->push(val_one+val_two);
            }
            if(postfix[i] == '-'){
                val_one = my_stack->peek()->val;
                my_stack->pop();
                val_two = my_stack->peek()->val;
                my_stack->pop();
                my_stack->push(val_two-val_one);
            }
            if(postfix[i] == '*'){
                val_one = my_stack->peek()->val;
                my_stack->pop();
                val_two = my_stack->peek()->val;
                my_stack->pop();
                my_stack->push(val_one*val_two);
            }
        }
    }
    return my_stack->peek()->val;
}

//For Testing purposes only!
MyQueue* MessageDecoder::getQueue(){
    return my_queue;
}

//For Testing purposes only!
MyStack* MessageDecoder::getStack(){
    return my_stack;
}