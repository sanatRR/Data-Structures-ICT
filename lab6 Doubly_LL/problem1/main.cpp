//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"DLL.h"
using namespace std;


int main(){
    DLL d1;
    d1.insertPos(0,1);
    d1.insertPos(6,7);
    d1.insertPos(11,4);
    d1.delPos(1);
    d1.delPos(7);
    d1.delPos(3);
    d1.insertBefore(100,3);
    d1.insertAfter(400,1);
    d1.display(false);
    d1.display(true);
    return 0;
}
