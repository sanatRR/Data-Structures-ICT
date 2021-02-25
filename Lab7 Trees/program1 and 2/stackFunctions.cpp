//Copyright (c) 2021 Sanat Raorane
#include"stackHead.h"
#include<iostream>
using namespace std;

Stack::Stack(){
    top=-1;
}


void Stack::push(elm e){
    if(!isFull()){
        arr[++top]=e;
    }else{
        cout<<"STACK FULL!"<<endl;
    }
}

elm Stack::pop(){
    if(!isEmpty()){
       return arr[top--];
    }else{
        cout<<"STACK EMPTY!, WARNING! NULL RETURNED!"<<endl;
        return NULL;
    }
}

bool Stack::isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}

bool Stack::isFull(){
    if(top==N-1)
        return true;
    else
        return false;
}

elm Stack::peek(){
    if(!isEmpty()){
       return arr[top];
    }else{
        cout<<"STACK EMPTY!, WARNING! NULL RETURNED!"<<endl;
        return NULL;
    }
}
