//Copyright (c) 2021 Sanat Raorane
#include"queueHead.h"
#include<iostream>
using namespace std;

Queue::Queue(){
    length=0;
    frontnode=rearnode=nullptr;
    char choice='y';
    do{
        length++;
        newnode=new Node;
        cout<<"\nEnter data"<<endl;
        cin>>newnode->data;
        newnode->next=nullptr;
        if(frontnode==nullptr){
            //Queue is empty
            frontnode=rearnode=newnode;
        }
        else{
            rearnode->next=newnode;
            rearnode=newnode;
        }
        cout<<"\nEnter another node?(y/n)"<<endl;
        cin.sync();
        cin>>choice;
    }while(choice=='y');
}

void Queue::enqueue(elm e){
    length++;
    newnode=new Node;
    newnode->data=e;
    newnode->next=nullptr;
    if(frontnode==nullptr){
        //queue is empty
        frontnode=rearnode=newnode;
    }
    else{
        rearnode->next=newnode;
        rearnode=newnode;
    }
}

elm Queue::dequeue(){
    length--;
    elm temp;
    Node *tempNode;
    if(frontnode==rearnode){
        //Queue has just 1 node
        temp=frontnode->data;
        delete frontnode;
        frontnode=rearnode=nullptr;
        return temp;
    }else{
        tempNode=frontnode;
        temp=tempNode->data;
        frontnode=frontnode->next;
        delete tempNode;
        return temp;
    }
}

elm Queue::peek(){
    return frontnode->data;
}

void Queue::display(){
    Node *tempnode;
    if(frontnode==nullptr){
        cout<<"\nQueue is Empty! "<<endl;
        return;
    }
    tempnode=frontnode;
    cout<<"\nThe Queue elements are "<<endl;
    while(tempnode!=nullptr){
        cout<<tempnode->data<<" ";
        tempnode=tempnode->next;
    }
}

bool Queue::isEmpty(){
    if(frontnode==nullptr)
        return true;
    else
        return false;
}

