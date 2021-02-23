//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"stackHead.h"
typedef int elm;
using namespace std;

int main(){
    //Driver Code
    char choice;
    elm temp;
    Stack s1;
    while(true){
        cout<<"\nEnter a choice:\nP:Push\nR:Pop\nT:Peek\nD:Display\nQ:Quit"<<endl;
        cin.sync();
        cin>>choice;
        switch(choice){
            case 'P':
                cout<<"\nEnter an element"<<endl;
                cin>>temp;
                s1.push(temp);
                break;
            case 'R':
                if(!s1.isEmpty())
                    cout<<"\n"<<s1.pop()<<" popped"<<endl;
                else
                    cout<<"\nStack is Empty!"<<endl;
                break;
            case 'T':
                if(!s1.isEmpty())
                    cout<<"\n"<<s1.peek()<<" is at the top"<<endl;
                else
                    cout<<"\nStack is Empty!"<<endl;
                break;
            case 'D':
                s1.display();
                break;
            case 'Q':
                return 0;
            default:
                cout<<"\nEnter a Valid Option!"<<endl;
        }
    }
}

