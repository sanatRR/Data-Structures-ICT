//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"student.h"
using namespace std;


void student::read(student arrayA[],int num){
    for(int i=0;i<num;i++){
        cout<<"\n\n"; //Lines for spacing
        cout<<"Enter details for student "<<(i+1)<<endl;
        cout<<"Enter Name:"<<endl;
        cin.sync();
        cin.get(arrayA[i].name,50);
        cout<<"Enter roll-number:"<<endl;
        cin>>arrayA[i].rollNo;
        cout<<"Enter grade:"<<endl;
        cin.sync();
        cin>>arrayA[i].grade;
    }
}

void student::display(student arrayA[],int num){
    cout<<"\n\n\n"; //lines for spacing
    for(int i=0;i<num;i++){
        cout<<"The details for roll no "<<arrayA[i].rollNo<<" are"<<endl;
        cout<<"Name: "<<arrayA[i].name<<endl;
        cout<<"Grade: "<<arrayA[i].grade<<endl;
    }
}

void student::sortArr(student arrayA[],int num){
    student temp;
    /*
    *Using Bubble Sort
    */
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-i-1;j++){
                if(arrayA[j].rollNo>arrayA[j+1].rollNo){
                    temp=arrayA[j];
                    arrayA[j]=arrayA[j+1];
                    arrayA[j+1]=temp;
                }
        }
    }
}
