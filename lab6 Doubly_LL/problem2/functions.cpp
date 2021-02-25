//Copyright (c) 2021 Sanat Raorane
#include"DLL.h"
#include<iostream>
using namespace std;

DLL::DLL(){
    head=tail=NULL;
    int degree;
    cout<<"\nEnter the degree of the polynomial"<<endl;
    cin>>degree;
    for(int i=degree;i>=0;i--){
        cout<<"\nEnter coefficient for power "<<i<<endl;
        newnode=new Node;
        newnode->pow=i;
        cin>>newnode->coeff;
        if(head==NULL){
            head=tail=newnode;
            head->prev=NULL;
            head->next=NULL;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=NULL;
            tail=newnode;
        }
    }
}

DLL::DLL(bool isEmpty){
    head=tail=NULL;
    if(isEmpty){
        return;
    }else{
        //Make a non-empty DLL
        DLL();
    }
}

void DLL::display(){
    Node *temp;
    temp=head;
    while(temp->next!=NULL){
        cout<<temp->coeff<<"x^"<<temp->pow<<" + ";
        temp=temp->next;
    }
    cout<<temp->coeff<<endl;
}

void DLL::add(Node* tail2){
    int i,greatestPow;
    DLL d1(true);
    //d1 will store the resultant of addition
    Node *temp1,*temp2,*addedHead,*addedTail;
    addedHead=addedTail=NULL;
    temp1=tail;
    temp2=tail2;
    /*Polynomials are being added in reverse order
    *i.e. from constant term -> max power
    */
    if(temp1->pow>=temp2->pow)
        greatestPow=temp1->pow;
    else
        greatestPow=temp2->pow;
    for(i=greatestPow;temp1!=NULL && temp2!=NULL;i--){
            newnode=new Node;
            newnode->coeff=temp1->coeff+temp2->coeff;
            newnode->pow=temp1->pow;
            if(addedHead==NULL){
                newnode->prev=NULL;
                newnode->next=NULL;
                addedTail=addedHead=newnode;
            }else{
                newnode->next=addedHead;
                newnode->prev=NULL;
                addedTail->prev=newnode;
                addedHead=newnode;
            }
            temp1=temp1->prev;
            temp2=temp2->prev;
    }
    if(temp1==NULL){
        while(temp2!=NULL){
                newnode=new Node;
                newnode->coeff=temp2->coeff;
                newnode->pow=temp2->pow;
                newnode->next=addedHead;
                newnode->prev=NULL;
                addedHead->prev=newnode;
                addedHead=newnode;
                temp2=temp2->prev;
        }
    }else if(temp2==NULL){
            while(temp1!=NULL){
                newnode=new Node;
                newnode->coeff=temp1->coeff;
                newnode->pow=temp1->pow;
                newnode->next=addedHead;
                newnode->prev=NULL;
                addedHead->prev=newnode;
                addedHead=newnode;
                temp1=temp1->prev;
            }
    }
    //addedHead is the head of resultant
    d1.head=addedHead;
    cout<<"\nThe Resultant equation is "<<endl;
    d1.display();
}

Node* DLL::getTail(){
    return tail;
}
