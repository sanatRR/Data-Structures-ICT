//Copyright (c) 2021 Sanat Raorane
/**
*Program to check is a string is palindrome
*using Stack
*/

#include"stackhead.h"
#include<iostream>
#include<string.h>
#define N 50

using namespace std;

int main(){
    Stack s1;
    char str[50];
    int flag=0;
    cout<<"\nEnter a String"<<endl;
    cin.sync();
    cin.get(str,50);
    /*
    *Push the string into a Stack
    */
    //typecast strlen(str) with int to prevent warning
    for(int i=0;i<(int)strlen(str);i++)
        s1.push(str[i]);
    /*
    *Now the stack contains inverted string
    *compare original string to one in stack
    */
    for(int i=0;i<(int)strlen(str);i++){
       if(str[i]!=s1.pop()){
            //If mismatch
            flag=-1;
            break;
        }
    }
    if(flag==-1)
        cout<<str<<" is not a palindrome"<<endl;
    else
        cout<<str<<" is a palindrome"<<endl;
}
