//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"student.h"
using namespace std;

int main(){
    //Driver Code
    int no;
    cout<<"\nEnter the number of students"<<endl;
    cin>>no;
    student s[30],temp;
    temp.read(s,no);
    temp.sortArr(s,no);
    temp.display(s,no);
}
