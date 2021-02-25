//Copyright (c) 2021 Sanat Raorane
#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include<iostream>
class Node{
public:
    int data;
    Node *left,*right;
    Node(){
        left=NULL;
        right=NULL;
    }
};


class BinaryTree{
public:
    Node *root,*newnode;
    /**
    *A no-arg constructor to iteratively
    *create a BinaryTree
    */
    BinaryTree();
    /**
    *Function to traverse the BinaryTree preorder
    */
    void preorder(Node* root);
    /**
    *Function to traverse the BinaryTree inorder
    *parameter root:The root of BinaryTree
    */
    void inorder(Node* root);
    /**
    *Function to traverse the BinaryTree postorder
    *parameter root:The root of BinaryTree
    */
    void postorder(Node *root);
    /**
    *Function to find number of leaf nodes
    *parameter root:The root of BinaryTree
    *return int: The number of leaf nodes
    */
    int leafCount(Node *root);
    ///////////////////////////////////////
    //////////////BST_FUNCTIONS////////////
    ///////////////////////////////////////
    /**
    *Function to insert a Node in a Binary
    *Search Tree
    *parameter: root:The current root of BST
    *key: The key to be inserted
    */
    Node* insertKey(Node* root,int key);
    /**
    *Function to delete a Node in a Binary
    *Search Tree
    *parameter: root:The current root of BST
    *key: The key to be deleted
    *return Node* : Pointer to new root
    */
    Node* deleteN(Node* root,int key);
    /**
    *Function to search for a node in a Binary
    *Search Tree
    *parameter:  root: The root of BST
    *key: The key to be searched
    *return Node* : Pointer to the node containing key
    */
    Node* searchN(Node* root,int ikey);
};


#endif // BINARYTREE_H_INCLUDED
