//Copyright (c) 2021 Sanat Raorane
/**
*Program to convert a number
*in base 10 format to any base
*/
#include"stackHead.h"
#include<iostream>
using namespace std;


int main(){
    int num,base;
    cout<<"\nEnter the number and desired base separated by space"<<endl;
    cin>>num>>base;
    Stack s1;
    while(num!=0)
    {
        /*
        *Push the remainder in a stack
        *till num is not zero
        */
        s1.push(num%base);
        num=num/base;
    }
    s1.display();
}
