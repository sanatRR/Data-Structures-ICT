//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main(){
    //Driver Code
    BinaryTree b1;
    b1.inorder(b1.root);
    b1.insertKey(b1.root,39);
    b1.insertKey(b1.root,90);
    b1.inorder(b1.root);
    b1.root=b1.deleteN(b1.root,39);
    Node *ptr;
    ptr=b1.searchN(b1.root,90);
    cout<<endl<<ptr->data<<endl;
    return 0;
}
