//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"DLL.h"
using namespace std;


int main(){
    DLL d1;
    d1.display(false);
    cout<<endl;
    d1.delPos(4);
    d1.insertPos(0,1);
    d1.insertRear(6);
    d1.insertBefore(2,3);
    d1.insertAfter(4,3);
    cout<<endl;
    d1.display(false);
    cout<<"\nDisplay in reverse"<<endl;
    d1.display(true);
    return 0;
}
