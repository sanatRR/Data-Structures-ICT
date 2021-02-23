//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"queueHead.h"
typedef int elm;
using namespace std;

int main(){
    //Driver Code
    char choice;
    elm temp;
    Queue q1;
    while(true){
        cout<<"\nEnter a choice:\nE:Enqueue\nR:Dequeue\nT:Peek\nD:Display\nQ:Quit"<<endl;
        cin.sync();
        cin>>choice;
        switch(choice){
            case 'E':
                cout<<"\nEnter an element"<<endl;
                cin>>temp;
                q1.enqueue(temp);
                break;
            case 'R':
                if(!q1.isEmpty())
                    cout<<"\n"<<q1.dequeue()<<" dequeued"<<endl;
                else
                    cout<<"\nQueue is Empty!"<<endl;
                break;
            case 'T':
                if(!q1.isEmpty())
                    cout<<"\n"<<q1.peek()<<" is at the front"<<endl;
                else
                    cout<<"\nQueue is Empty!"<<endl;
                break;
            case 'D':
                q1.display();
                break;
            case 'Q':
                return 0;
            default:
                cout<<"\nEnter a Valid Option!"<<endl;
        }
    }
}
