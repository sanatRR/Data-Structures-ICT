//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"SLL.h"
using namespace std;

int main(){
    //driver code;
   SLL s1;
   s1.insertBefore(1,0);
   s1.insertBefore(3,2);
   s1.insertBefore(5,4);
   s1.insertBefore(7,6);
   s1.display();
   return 0;
}

