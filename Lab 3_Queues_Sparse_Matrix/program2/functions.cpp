//Copyright (c) 2021 Sanat Raorane
#include"sparseHead.h"
#include<iostream>
#define N 100
using namespace std;

sparseHead::sparseHead(){
    nonzeroct=0;
    cout<<"Enter the number of rows and columns "<<endl;
    cin>>m>>n;
    convert();
}

void sparseHead::convert(){
    int temp[m][n];
    cout<<"\nEnter the matrix elements one by one "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>temp[i][j];
            if(temp[i][j]!=0)
                nonzeroct++;
        }
    }

    t[0].row=m;
    t[0].column=n;
    t[0].element=nonzeroct;
    int k=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(temp[i][j]!=0){
                t[k].row=i;
                t[k].column=j;
                t[k].element=temp[i][j];
                k++;
            }
        }
    }
}

void sparseHead::display(){
    for(int i=0;i<=t[0].element;i++)
    {
        cout<<"  "<<t[i].row<<"\t|\t"<<t[i].column<<"\t|\t"<<t[i].element<<endl;
        cout<<"------------------------------------"<<endl; //Line for spacing
    }
    cout<<"\n\n\n"; //Lines for spacing
}

void sparseHead::fTranspose(){
    triples result[nonzeroct+1];
    int rowterms[t[0].column],startpos[t[0].column];
    //Initialize both arrays to zero
    for(int i=0;i<t[0].column;i++){
        rowterms[i]=0;
        startpos[i]=0;
    }

    //rowterm calculates frequency for each column element
    for(int i=1;i<=t[0].element;i++)
        rowterms[t[i].column]++;

    startpos[0]=1;
    for(int i=1;i<=t[0].element;i++)
        startpos[i]=startpos[i-1]+rowterms[i-1];

    int j;
    for(int i=1;i<=nonzeroct;i++){
        j=startpos[t[i].column]++;
        result[j].column=t[i].row;
        result[j].row=t[i].column;
        result[j].element=t[i].element;
    }

    for(int i=1;i<=nonzeroct;i++)
    {
        cout<<"  "<<result[i].row<<"\t|\t"<<result[i].column<<"\t|\t"<<result[i].element<<endl;
        cout<<"------------------------------------"<<endl;
    }
    cout<<"\n\n\n"; //Lines for spacing
}
