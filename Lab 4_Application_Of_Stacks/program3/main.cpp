//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"stackHead.h"
using namespace std;

/**
*Function to convert a given infix to
*fully parenthesized infix
*parameter input: The postfix string
*/
string postfixInfix(string input){
    Stack s1;
    for(int i=0;input[i]!='\0';i++){
            /*
            *Push operands directly to stack
            */
        if(input[i]>='0' && input[i]<='9'){
            //Before pushing, convert char to string
            string s(1,input[i]);
            s1.push(s);
        }
        else{
            string top2=s1.pop();
            string top1=s1.pop();
            string operand(1,input[i]);
            /*
            *Add parenthesis and operand
            */
            s1.push("("+top1+operand+top2+")");
        }
    }
    return s1.peek();
}
int main(){
    //Driver code
    cout<<"\nEnter a postfix expression, leave no whitespace!"<<endl;
    string input;
    cin>>input;
    cout<<endl<<postfixInfix(input);
    return 0;
}
