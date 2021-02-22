//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"sparseHead.h"
using namespace std;

int main(){
    sparseHead s1;
    cout<<"The original Triple Array is "<<endl;
    s1.display();
    cout<<"The Triple Array after transpose is "<<endl;
    s1.fTranspose();
}
