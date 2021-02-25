//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"DLL.h"
using namespace std;

DLL::DLL(){
    length=0;
    head=tail=NULL;
    char choice='y';
    do{
        newnode=new Node;
        length++;
        cout<<"Enter data:"<<endl;
        cin>>newnode->data;
        newnode->next=NULL;
        if(head==NULL){
            head=tail=newnode;
            head->prev=NULL;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        cout<<"Enter another node?(y/n)"<<endl;
        cin.sync();
        cin>>choice;
    }while(choice=='y');
}

void DLL::display(bool inReverse){
    if(head==NULL){
         cout<<"Doubly LinkedList is Empty!"<<endl;
         return;
    }
    Node *temp;
    if(!inReverse){
        temp=head;
        cout<<"The Doubly LinkedList contents are"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }else{
        temp=tail;
        cout<<"The Doubly LinkedList contents are"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }
}

void DLL::insertRear(elm e){
    newnode=new Node;
    newnode->next=NULL;
    newnode->data=e;
    if(head==NULL){
        head=tail=newnode;
        head->prev=NULL;
    }else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    length++;
}

void DLL::deleteRear(){
    if(head==NULL){
        cout<<"Nothing to delete"<<endl;
        return;
    }else if(head==tail){
        cout<<tail->data<<" deleted"<<endl;
        tail=head=NULL;
        length--;
        return;
    }else{
        tail=tail->prev;
        cout<<tail->next->data<<" deleted"<<endl;
        delete tail->next;
        tail->next=NULL;
        length--;
    }
}

void DLL::insertPos(elm e,int pos){
    if(pos<1 || pos>length+1){
        cout<<"\nInvalid Position"<<endl;
        return;
    }else{
        newnode=new Node;
        newnode->data=e;
        if(pos==1){
            if(length==0){
                head=newnode;
                head->prev=NULL;
                head->next=NULL;
            }else{
                head->prev=newnode;
                newnode->next=head;
                newnode->prev=NULL;
                head=newnode;
            }
        }else if(pos==(length+1)){
                    insertRear(e);
                    length--;   //else length will be incremented twice
        }
        else{
            Node *temp;
            temp=head;
            for(int i=1;i<pos;i++){
                temp=temp->next;
            }
            newnode->next=temp;
            temp->prev->next=newnode;
            newnode->prev=temp->prev;
            temp->prev=newnode;
        }
        length++;
    }
}

void DLL::delPos(int pos){
    if(pos<1 || pos>length)
        cout<<"Invalid Position"<<endl;
    else{
        //Position is valid
        if(pos==1){
            if(head==tail){
                //Just 1 node in the DLL
                cout<<head->data<<" deleted"<<endl;
                delete head;
                head=tail=NULL;
            }else{
                head=head->next;
                cout<<head->prev->data<<" deleted"<<endl;
                delete head->prev;
                head->prev=NULL;
            }
        }else if(pos==length){
            if(head==tail){
                //Just 1 node in the DLL
                cout<<tail->data<<" deleted"<<endl;
                delete tail;
                head=tail=NULL;
            }else{
                tail=tail->prev;
                cout<<tail->next->data<<" deleted"<<endl;
                delete tail->next;
                tail->next=NULL;
            }
        }else{
            Node *temp,*preTemp;
            temp=head;
            preTemp=NULL;
            for(int i=1;i<pos;i++){
                preTemp=temp;
                temp=temp->next;
            }
            preTemp->next=temp->next;
            temp->next->prev=temp->prev;
            cout<<temp->data<<" deleted"<<endl;
            delete temp;
        }
        length--;
    }
}

void DLL::insertBefore(elm e,elm before){
    cout<<"debug1"<<endl;
    if(head==NULL){
        cout<<before<<" doesn't exist"<<endl;
        return;
    }else{
    cout<<"debug2"<<endl;
        Node *temp;
        temp=head;
        int pos=1;
        while(temp!=NULL && temp->data!=before){
            temp=temp->next;
            pos++;
        }
        if(temp==NULL){
            cout<<before<<" doesn't exist"<<endl;
            return;
        }else{
    cout<<"debug3"<<endl;
            insertPos(e,pos);
        }
    cout<<"debug4"<<endl;
    }
}

void DLL::insertAfter(elm e,elm after){
    cout<<"debug1"<<endl;
    if(head==NULL){
        cout<<after<<" doesn't exist"<<endl;
        return;
    }else{
    cout<<"debug2"<<endl;
        Node *temp;
        temp=head;
        int pos=1;
        while(temp!=NULL && temp->data!=after){
            temp=temp->next;
            pos++;
        }
        if(temp==NULL){
            cout<<after<<" doesn't exist"<<endl;
            return;
        }else{
    cout<<"debug3"<<endl;
            insertPos(e,pos+1);
        }
    cout<<"debug4"<<endl;
    }
}
