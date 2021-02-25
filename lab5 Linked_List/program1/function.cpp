//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"SLL.h"
using namespace std;

SLL::SLL(){
    head=tail=NULL;
    char choice='y';
    do{
        newnode=new Node;
        cout<<"Enter the data:"<<endl;
        cin>>newnode->data;
        newnode->next=NULL;
        if(head==NULL){
            //LinkedList is empty
            head=tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
        cout<<"\nEnter another node?(y/n)"<<endl;
        cin>>choice;
    }while(choice=='y');
}

void SLL::display(){
    if(head==NULL)
        cout<<"The LinkedList is empty"<<endl;
    Node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void SLL::insertBeg(elm e){
    newnode=new Node;
    newnode->data=e;
    newnode->next=NULL;
    if(head==NULL){
        //LinkedList is empty
        head=tail=newnode;
    }else{
        newnode->next=head;
        head=newnode;
    }
}


void SLL::insertE(elm e){
    newnode=new Node;
    newnode->data=e;
    newnode->next=NULL;
    if(head==NULL){
        //LinkedList is empty
        head=tail=newnode;
    }else{
        tail->next=newnode;
        tail=newnode;
    }
}

void SLL::del(elm e){
    if(head==NULL){
        cout<<"LinkedList is Empty, Nothing to delete"<<endl;
        return;
    }

    Node *temp,*preTemp;
    /*temp will reach the node to be deleted
    *preTemp will lag temp by 1 node
    */
    temp=head;
    preTemp=NULL;
    //First search for the element to be deleted
    while(temp!=NULL && temp->data!=e){
        preTemp=temp;
        temp=temp->next;
    }
    if(temp==NULL){
         cout<<e<<" Not found"<<endl;
         return;
    }
    if(temp==head || temp==tail){
        if(head==tail){
            //LinkedList has a single node
            cout<<temp->data<<" deleted"<<endl;
            delete head;
            head=tail=NULL;
        }else if(temp==head){
            head=head->next;
            delete temp;
        }else if(temp==tail){
            tail=preTemp;
            tail->next=NULL;
            cout<<temp->data<<" deleted"<<endl;
            delete temp;
        }
    }else{
        //Node to be deleted is intermediate
        preTemp->next=temp->next;
        cout<<temp->data<<" deleted"<<endl;
        delete temp;
    }
}

void SLL::insertAfter(elm after,elm e){
    if(head==NULL){
        //LinkedList is Empty
        cout<<after<<" doesn't exist"<<endl;
        return;
    }
    Node *temp;
    temp=head;
    //search for after
    while(temp->data!=after)
        temp=temp->next;
    if(temp!=NULL){
        //after exists
        if(temp==tail)
            insertE(e);
        else{
            newnode=new Node;
            newnode->data=e;
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }else{
        cout<<after<<" doesn't exist"<<endl;
    }
}

void SLL::insertBefore(elm before,elm e){
    if(head==NULL){
        cout<<before<<" doesn't exist"<<endl;
        return;
    }else{
        /*temp will reach the before node
        *preTemp will lag temp by 1 node
        */
        Node *temp,*preTemp;
        temp=head;
        preTemp=NULL;
        //search for before
        while(temp->data!=before){
            preTemp=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<before<<" doesn't exist"<<endl;
            return;
        }else{
            if(temp==head)
                insertBeg(e);
            else{
                //intermediate node to be inserted
                newnode=new Node;
                newnode->data=e;
                newnode->next=preTemp->next;
                preTemp->next=newnode;
            }
        }
    }

}








