//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"stackHead.h"
#define N 50
using namespace std;

/**
*Function to convert a
*given infix array to postfix
*/
void infixPostfix(char arrayInf[]){
    Stack s1;
    for(int i=0;arrayInf[i]!='\0';i++){
            /*
            *If operand found, then simply print
            */
        if(arrayInf[i]>='0' && arrayInf[i]<='9')
            cout<<arrayInf[i];
        else{
            if(arrayInf[i]=='(' || arrayInf[i]==')'){
                if(arrayInf[i]=='(')
                    s1.push(arrayInf[i]);
                else{
                    /*
                    *If ')' found then keep popping,
                    *printing till '(' is found
                    */
                    while(s1.peek()!='('){
                        cout<<s1.pop();
                    }
                    s1.pop(); //pop '(' but dont print it.
                }
            } //Use the associativity rules
            else if(arrayInf[i]=='^')
                s1.push(arrayInf[i]);
            else if(arrayInf[i]=='*' || arrayInf[i]=='/'){
                if(!s1.isEmpty() && (s1.peek()=='+' || s1.peek()=='-'))
                    s1.push(arrayInf[i]);
                else if(!s1.isEmpty()){
                    cout<<s1.pop();
                    i--;
                    continue;
                }else
                    s1.push(arrayInf[i]);
            }else if(arrayInf[i]=='+' || arrayInf[i]=='-'){
                if(!s1.isEmpty()){
                    cout<<s1.pop();
                    i--;
                    continue;
                }else
                    s1.push(arrayInf[i]);
            }
        }
    }
    /*
    *Pop and print till stack is empty
    */
    while(!s1.isEmpty())
        cout<<s1.pop();
}

int main(){
    char arr[N];
    cout<<"\nEnter an Infix expression"<<endl;
    cin.sync(); //clear buffer
    cin.get(arr,49);
    cout<<"infix: "<<arr<<endl;
    cout<<"postfix: ";
    infixPostfix(arr);
    return 0;
}
