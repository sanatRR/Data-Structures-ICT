//Copyright (c) 2021 Sanat Raorane
/**
*Program to implement Stack using LinkedList
*/

#ifndef STACKHEAD_H_INCLUDED
#define STACKHEAD_H_INCLUDED
typedef int elm;

class Queue{
private:
    class Node{
    public:
        int data;
        Node* next;
    };
    Node *newnode,*frontnode,*rearnode;
    int length; //length of queue
public:
    /**
    *A public no-arg constructor
    *for the Queue class
    */
    Queue();
    /**
    *Function to enqueue an element
    */
    void enqueue(elm e);
    /**
    *Function to dequeue the first element
    *returns elm: The first element
    *call isEmpty prior to calling this function
    */
    elm dequeue();
    /**
    *Function to return the first element
    *return elm: The first element
    *Call isEmpty prior to calling this function
    */
    elm peek();
    /**
    *Function to display the Queue
    *from front to rear
    */
    void display();
    /**
    *Function to check if the Queue is empty
    *returns true: If the queue is empty, false: If the queue is not empty
    */
    bool isEmpty();
};


#endif // STACKHEAD_H_INCLUDED
