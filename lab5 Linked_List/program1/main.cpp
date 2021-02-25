//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"SLL.h"
using namespace std;

int main(){
    //driver code;
   SLL s1;
   int choice;
   int temp1,temp2;
   while(true){
        cout<<"\nEnter choice:\n1:Insert at end\n2:Insert at beginning\n3:display\n4:delete an element\n5:Insert an element after another\n6:Insert an element before another\n7:Quit"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"\nEnter data:";
            cin>>temp1;
            s1.insertE(temp1);
            break;
        case 2:
            cout<<"\nEnter data:";
            cin>>temp1;
            s1.insertBeg(temp1);
            break;
        case 3:
            s1.display();
            break;
        case 4:
            cout<<"\nEnter the element to be deleted"<<endl;
            cin>>temp1;
            s1.del(temp1);
            break;
        case 5:
            cout<<"\nEnter the element to be inserted, after element"<<endl;
            cin>>temp1>>temp2;
            s1.insertAfter(temp2,temp1);
            break;
        case 6:
            cout<<"\nEnter the element to be inserted, before element"<<endl;
            cin>>temp1>>temp2;
            s1.insertBefore(temp2,temp1);
            break;
        case 7:
            return 0;
        }
   }
}

