//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"SLL.h"
using namespace std;

int main(){
    //driver code;
   SLL s1;
   s1.insertBeg(0);
   s1.insertE(6);
   s1.insertBefore(3,2);
   s1.insertAfter(3,4);
   s1.display();
   cout<<endl;
   s1.del(0);
   s1.del(2);
   s1.del(4);
   s1.del(6);
   s1.display();
   return 0;
}

