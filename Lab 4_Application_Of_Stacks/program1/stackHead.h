//Copyright (c) 2021 Sanat Raorane
/**
*Program to implement Stack using LinkedList
*/

#ifndef STACKHEAD_H_INCLUDED
#define STACKHEAD_H_INCLUDED
typedef char elm;

class Stack{
private:
    class Node{
        public:
            elm data;
            Node* next;
    };
    Node *top,*newnode,*head;
public:
    /**
    *A no-arg constructor for Stack class
    */
    Stack();
    /**
    *Function to push elements into
    *the stack
    *parameter data: data to be inserted
    */
    void push(elm data);
    /**
    *Function to pop element from the stack
    *return elm: The topmost element
    *call isEmpty before calling this function
    */
    elm pop();
    /**
    *Function to get element from top of stack
    *return elm: The topmost element
    *call isEmpty before calling this function
    */
    elm peek();
    /**
    *Function to check if the Stack is empty
    *return true: If stack is empty, false: If stack is not empty
    */
    bool isEmpty();
    /**
    *Function to display the Stack elements from head to top
    */
    void display();
};


#endif // STACKHEAD_H_INCLUDED
