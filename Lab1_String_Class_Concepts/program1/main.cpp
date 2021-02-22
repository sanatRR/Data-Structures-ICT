//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"stringhead.h"
using namespace std;

int main(){
    //Driver Code
    //Finding length
    String a("Hello World");
  /*  cout<<a.length()<<endl;
    //Comparison
    String b("hello world");
    cout<<a.stringCompare(b.arrayA)<<endl;
    //Concatenation
    String c(" in C++");
    cout<<a.stringConcat(c.arrayA)<<endl;
    //insert substring
    a.insertSubstring("in C++",5);
    cout<<a.arrayA<<endl;
    //Delete subString*/
    a.deleteSubstring("Hello");
    cout<<a.arrayA<<endl;
    return 0;
}

