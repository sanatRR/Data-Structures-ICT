//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"DLL.h"
using namespace std;


int main(){
    DLL d1;
    int choice,temp1,temp2;
    while(true){
        cout<<"\nEnter a choice:\n1.Insert at Rear\n2.Delete from rear\n3.Insert at specific position\n4.Delete from specific position\n5.Insert before another element\n6.Insert after another element\n7.Display\n8.Quit"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"\nEnter data"<<endl;
            cin>>temp1;
            d1.insertRear(temp1);
            break;
        case 2:
            d1.deleteRear();
            break;
        case 3:
            cout<<"\nEnter element and position"<<endl;
            cin>>temp1>>temp2;
            d1.insertPos(temp1,temp2);
            break;
        case 4:
            cout<<"\nEnter position of deletion"<<endl;
            cin>>temp1;
            d1.delPos(temp1);
            break;
        case 5:
            cout<<"\nEnter element and before element"<<endl;
            cin>>temp1>>temp2;
            d1.insertBefore(temp1,temp2);
            break;
        case 6:
            cout<<"\nEnter element and after element"<<endl;
            cin>>temp1>>temp2;
            d1.insertAfter(temp1,temp2);
            break;
        case 7:
            d1.display(false);
            break;
        case 8:
            return 0;
        }
    }
}
