//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"stackHead.h"
#define N 50

using namespace std;

/**
*Helper function for evalPostfix
*parameter top1: first operand, top2: second operand, operatr: The operator
*/
int calculate(int top1,int top2,char operatr){
    switch(operatr){
        case '+':
            return top1+top2;
        case '-':
            return top1-top2;
        case '*':
            return top1*top2;
        case '/':
            return top1/top2;
        case '^':
            return top1^top2;
    }
}

/**
*Function to evaluate a postfix expression
*parameter arrayA: The input postfix array
*/
int evalPostfix(char arrayA[]){
    Stack s1;
    for(int i=0;arrayA[i]!='\0';i++){
        /*
        *If operand then push to the stack
        *subtract '0' to convert to decimal digit
        */
        if(arrayA[i]>='0' && arrayA[i]<='9')
            s1.push(arrayA[i]-'0');
        else{
         int top2=s1.pop();
         int top1=s1.pop();
         s1.push(calculate(top1,top2,arrayA[i]));
        }
    }
    return s1.pop();
}

int main(){
    //Driver Code
    char input[N];
    cout<<"Enter a postfix expression, leave no whitespaces!"<<endl;
    cin.sync(); //clear buffer
    cin.get(input,49);
    cout<<endl<<evalPostfix(input);
    return 0;
}

