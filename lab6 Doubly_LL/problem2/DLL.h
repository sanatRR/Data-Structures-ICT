//Copyright (c) 2021 Sanat Raorane
#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

/**
*Node class for the DLL
*/
class Node{
    public:
        int coeff,pow;
        Node *prev,*next;
};

class DLL{
public:
    Node *newnode,*head,*tail;
    /**
    *Function to add the current DLL polynomial
    *with the DLL polynomial whose tail is passed
    *parameter tail2: The head of second polynomial
    */
    void add(Node *tail2);
    /**
    *Function to get tail of a DLL
    *return Node*: A pointer to the tail
    */
    Node* getTail();
    /**
    *A no-arg constructor for the DLL class
    *Used to create a non-empty DLL
    */
    DLL();
    /**
    *A constructor for DLL class
    *Can be used to make either empty or non-empty DLL
    *parameter isEmpty: If true, then empty DLL is made
    */
    DLL(bool isEmpty);
    /**
    *Function to display a DLL polynomial from
    *head to  tail
    */
    void display();
};


#endif // DLL_H_INCLUDED
