//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"stackHead.h"
#define N 50
using namespace std;

Stack::Stack(){
    head=nullptr;
    length=0;
}

void Stack::display(){
    /*
    *temp will be used for traversal
    */
    Node *temp;
    temp=head;
    /*
    *arr being used to invert the display
    */
    int arr[N];
    if(head==nullptr){
        cout<<"\nStack is Empty!"<<endl;
        return;
    }
    int i=0;
    while(temp->next!=nullptr){
        arr[i++]=temp->data;
        temp=temp->next;
    }
    arr[i]=temp->data; //print top separately
    cout<<"\nThe converted number is "<<endl;
    for(int i=length-1;i>=0;i--)
        cout<<arr[i];
}

void Stack::push(elm data){
    length++;
    newnode=new Node;
    /*
    *Copy data to the newnode
    */
    newnode->data=data;
    /*
    *Assuming node to be terminal, next must be null
    */
    newnode->next=nullptr;
    if(head==nullptr)
        head=top=newnode;
    else{
        top->next=newnode;
        top=newnode;
    }
}

elm Stack::pop(){
    elm temp;
    Node* tempnode;
    if(head->next==nullptr){
        //Stack has a single element
        temp=head->data;
        delete head;
        head=nullptr;
        return temp;
    }else{
        /*If stack has multiple elements
        *reach to second-last element
        */
        tempnode=head;
        while(tempnode->next!=top){
            tempnode=tempnode->next;
        }
        /*
        *Copy data from node to be deleted
        */
        temp=top->data;
        /*
        *Delete topmost node, release memory
        */
        delete top;
        /*
        *Second-last node becomes last node
        */
        top=tempnode;
        top->next=nullptr;
        return temp;
    }
}

bool Stack::isEmpty(){
    if(head==nullptr)
        return true;
    else
        return false;
}

elm Stack::peek(){
    return top->data;
}
