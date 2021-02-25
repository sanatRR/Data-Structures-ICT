//Copyright (c) 2021 Sanat Raorane
#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
typedef int elm;
class DLL{
private:
    /**
    *Node class for the Doubly
    *LinkedList
    */
    class Node{
    public:
        Node *next,*prev;
        elm data;
    };
Node *newnode,*head,*tail;
public:
    int length;
    /**
    *Function to display the contents
    *of the doubly LinkedList
    *parameter inReverse: If true then DLL will be
    *traversed from tail to head
    */
    void display(bool inReverse);
    /**
    *A no-arg constructor for
    *Doubly LinkedList
    */
    DLL();
    /**
    *Function to insert an element at the rear of a
    *Doubly LinkedList
    *parameter e:The element to be inserted
    */
    void insertRear(elm e);
    /**
    *Function to delete an element from the rear of a
    *Doubly LinkedList
    */
    void deleteRear();
    /**
    *Function to insert an element at a given position in
    *the Doubly LinkedList
    *parameter e: The element to be inserted, pos: The position of insertion (pos=index+1)
    */
    void insertPos(elm e,int pos);
    /**
    *Function to delete an element from a given position in a
    *Doubly LinkedList
    *parameter pos: The position at which deletion must occur
    */
    void delPos(int pos);
    /**
    *Function to insert an element before a given element in a
    *Doubly LinkedList
    *parameter before: The element before which insertion is to be performed,
    *e: The element to be inserted
    */
    void insertBefore(elm e,elm before);
    /**
    *Function to insert an element after a given element in a
    *Doubly LinkedList
    *parameter after: The element after which insertion is to be performed
    *e: The element to be inserted
    */
    void insertAfter(elm e,elm after);
};


#endif // DLL_H_INCLUDED
