//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"stackHead.h"
#define N 50
using namespace std;

/**
*Function to convert given infix expression to prefix
*parameter infix: The given infix expression
*Algorithm:
*1.reverse the given infix expression
*2.Replace ')' <---> '('
*3.Find postfix and then reverse it
*/

void infixPrefix(char infix[]){
    char temp[N];
    int i;
    /*
    *To reverse the infix expression
    *use stack and then copy to temp
    */
    Stack reverser;
    for(i=0;infix[i]!='\0';i++)
        reverser.push(infix[i]);
    for(i=0;!reverser.isEmpty();i++){
        temp[i]=reverser.pop();
    }
    temp[i]='\0';
    /*
    *Replace ')' with '('
    */
    for(int i=0;temp[i]!='\0';i++){
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }
    /*
    *Find postfix and store the
    *output again in reverser stack
    */
    Stack s1; //Stack s1 to find postfix
    for(int i=0;temp[i]!='\0';i++){
            /*
            *If operand found, then simply print
            */
        if(temp[i]>='0' && temp[i]<='9')
            reverser.push(temp[i]);
        else{
            if(temp[i]=='(' || temp[i]==')'){
                if(temp[i]=='(')
                    s1.push(temp[i]);
                else{
                    /*
                    *If ')' found then keep popping,
                    *printing till '(' is found
                    */
                    while(s1.peek()!='('){
                        reverser.push(s1.pop());
                    }
                    s1.pop(); //pop '(' but dont print it.
                }
            } //Use the associativity rules
            else if(temp[i]=='^')
                s1.push(temp[i]);
            else if(temp[i]=='*' || temp[i]=='/'){
                if(!s1.isEmpty() && (s1.peek()=='+' || s1.peek()=='-'))
                    s1.push(temp[i]);
                else if(!s1.isEmpty()){
                    reverser.push(s1.pop());
                    i--;
                    continue;
                }else
                    s1.push(temp[i]);
            }else if(temp[i]=='+' || temp[i]=='-'){
                if(!s1.isEmpty()){
                    reverser.push(s1.pop());
                    i--;
                    continue;
                }else
                    s1.push(temp[i]);
            }
        }
    }
    /*
    *Pop and print till stack is empty
    */
    while(!s1.isEmpty())
        reverser.push(s1.pop());

    /*
    *Pop all elements from reverser
    */
    cout<<"\nThe prefix expression is "<<endl;
    while(!reverser.isEmpty())
        cout<<reverser.pop();
}

int main(){
    //Driver Code
    cout<<"\nEnter an infix expression, leave no whitespaces!"<<endl;
    char arr[N];
    cin.get(arr,50);
    infixPrefix(arr);
    return 0;
}
