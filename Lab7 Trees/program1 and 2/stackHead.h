//Copyright (c) 2021 Sanat Raorane
#ifndef STACKHEAD_H_INCLUDED
#define STACKHEAD_H_INCLUDED
#define N 100
#include"BinaryTree.h"
typedef Node* elm;

class Stack{
private:
    elm arr[N];
    int top;
public:
    /**
    *Function to push an element into the stack
    *parameter e: The element to be pushed
    */
    void push(elm e);
    /**
    *Function to pop an element from the stack
    *return e: The popped element
    */
    elm pop();
    /**
    *Function to check if the stack is empty
    *return true: If the stack is empty else false
    */
    bool isEmpty();
    /**
    *Function to check is the stack is full
    *return true: If the stack is full else false
    */
    bool isFull();
    /**
    *Function to return the topmost stack element
    *Return e: The topmost stack element
    */
    elm peek();
    /**
    *A no-arg constructor for the Stack class
    */
    Stack();
};


#endif // STACKHEAD_H_INCLUDED
