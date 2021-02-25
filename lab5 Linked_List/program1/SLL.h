//Copyright (c) 2021 Sanat Raorane
#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
typedef int elm;

class SLL{
private:
    /**
    *Node class for Singly
    *LinkedList
    */
    class Node{
     public:
        elm data;
        Node* next;
    };
    Node *head,*newnode,*tail;
public:
    /**
    *Function to insert elements into the LinkedList at the end
    *parameter e: The element to be added
    */
    void insertE(elm e);
    /**
    *Function to insert an element at the beginning
    *Parameter e: The element to be inserted
    */
    void insertBeg(elm e);
    /**
    *Function to display elements present in the LinkedList
    */
    void display();
    /**
    *A no-arg constructor for the SLL class
    */
    SLL();
    /**
    *Function to delete given element from the LinkedList
    *parameter e: The element to be deleted
    */
    void del(elm e);
    /**
    *Function to insert an element after a given element
    *parameter after: The element after which insertion is needed, e: The element to be inserted
    */
    void insertAfter(elm after,elm e);
    /**
    *Function to insert an element before a given element
    *parameter before: The element before which insertion is needed, e: The element to be inserted
    */
    void insertBefore(elm before,elm e);
};


#endif // SLL_H_INCLUDED
