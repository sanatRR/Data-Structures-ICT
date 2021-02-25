//Copyright (c) 2021 Sanat Raorane
#include"stackHead.h"
#include<iostream>
#include"BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree(){
    root=NULL;
    Node *ptr;
    //Stack for construction of binary tree
    Stack s1;
    newnode=new Node;
    char choice='y';
    cout<<"Enter data for the root node"<<endl;
    cin>>newnode->data;
    ptr=root=newnode;
    int flag=0;
    while(flag==0){
        if(flag!=0)
            break;
        while(true){
            cout<<"Make left child of "<<ptr->data<<" ?(y/n)"<<endl;
            cin>>choice;
            if(choice=='y'){
                newnode=new Node;
                cout<<"Enter data"<<endl;
                cin>>newnode->data;
                ptr->left=newnode;
                s1.push(ptr);
                ptr=ptr->left;
            }else{
                break;
            }
        }
        while(true){
            cout<<"Make right child of "<<ptr->data<<" ?(y/n)"<<endl;
            cin.sync();
            cin>>choice;
            if(choice=='y'){
                newnode=new Node;
                cout<<"Enter data"<<endl;
                cin>>newnode->data;
                ptr->right=newnode;
                ptr=ptr->right;
                break;
            }else{
                if(s1.isEmpty()){
                    flag=1;
                    break;
                }else{
                    ptr=s1.pop();
                    continue;
                }
            }
        }
    }
}

void BinaryTree::preorder(Node* root){
    Node *ptr;
    Stack s1;
    ptr=root;
    if(ptr==NULL){
        cout<<"\nTree does not exist"<<endl;
        return;
    }
    cout<<"\nThe preorder traversal is"<<endl;
    s1.push(ptr);
    while(!s1.isEmpty()){
        ptr=s1.pop();
        cout<<ptr->data<<" ";
        if(ptr->right!=NULL)
            s1.push(ptr->right);
        if(ptr->left!=NULL)
            s1.push(ptr->left);
    }
    cout<<endl;
}

void BinaryTree::inorder(Node* root){
    Node *ptr;
    ptr=root;
    Stack s1;
    if(ptr==NULL){
        cout<<"Tree does not exist"<<endl;
        return;
    }
    cout<<"\nThe inorder traversal is"<<endl;
    while(true){
        while(ptr->left!=NULL){
            s1.push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right==NULL){
            cout<<ptr->data<<" ";
            if(s1.isEmpty())
                return;
            ptr=s1.pop();
        }
        cout<<ptr->data<<" ";
        ptr=ptr->right;
    }
    cout<<endl;
}

void BinaryTree::postorder(Node* root){
    Node *q,*ptr;
    ptr=root;
    Stack s1;
    if(ptr==NULL){
        cout<<"Tree does not exist"<<endl;
        return;
    }
    cout<<"\nThe postorder traversal is"<<endl;
    q=root;
    while(true){
        while(ptr->left!=NULL){
            s1.push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right==NULL || ptr->right==q){
            cout<<ptr->data<<" ";
            q=ptr;
            if(s1.isEmpty())
                return;
            ptr=s1.pop();
        }
        s1.push(ptr);
        ptr=ptr->right;
    }
    cout<<endl;
}

int BinaryTree::leafCount(Node *ptr){
    static int leafCountNum=0;
    if(ptr==NULL){
        return 0;
    }
    if(ptr->left==NULL && ptr->right==NULL){
        leafCountNum++;
    }
    leafCount(ptr->left);
    leafCount(ptr->right);
    return leafCountNum;
}

Node* BinaryTree::insertKey(Node* root,int key){
    Node *temp,*parent,*ptr;
    ptr=root;
    parent=NULL;
    while(ptr!=NULL){
        parent=ptr;
        if(key<ptr->data)
            ptr=ptr->left;
        else if(key>ptr->data)
            ptr=ptr->right;
        else{
            cout<<"key "<<key<<" already exists"<<endl;
            return root;
        }
    }
    temp=new Node;
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    if(parent==NULL)
        root=temp;
    else if(key<parent->data)
        parent->left=temp;
    else
        parent->right=temp;
    return root;
}

Node* BinaryTree::deleteN(Node* ptr,int key){
    Node *temp,*succ;
    if(ptr==NULL){
        cout<<"\nKey not found"<<endl;
        return ptr;
    }
    if(key<ptr->data)
        ptr->left=deleteN(ptr->left,key);
    else if(key>ptr->data)
        ptr->right=deleteN(ptr->right,key);
    else{
        if(ptr->left!=NULL && ptr->right!=NULL){
            succ=ptr->right;
            while(succ->left)
                succ=succ->left;
            ptr->data=succ->data;
            ptr->right=deleteN(ptr->right,succ->data);
        }else{
            temp=ptr;
            if(ptr->left!=NULL)
                ptr=ptr->left;
            else if(ptr->right!=NULL)
                ptr=ptr->right;
            else
                ptr=NULL;
            delete temp;
        }
    }
    return ptr;
}

Node* BinaryTree::searchN(Node* ptr,int key){
    if(ptr==NULL){
        cout<<"key not found"<<endl;
        return NULL;
    }else if(key<ptr->data)
        return searchN(ptr->left,key);
    else if(key>ptr->data)
        return searchN(ptr->right,key);
    else
        return ptr;
}


