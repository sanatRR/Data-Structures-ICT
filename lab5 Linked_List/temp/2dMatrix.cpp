#include<iostream>
using namespace std;

class Mat{
public:

    class ColumnNode{
    public:
        ColumnNode* next;
        int data;
    ColumnNode(){
        next=NULL;
    }
    };
    ColumnNode *newColumnNode,*tempColumnNode;
    class RowNode{
    public:
        ColumnNode* head;
        RowNode* next;
    RowNode(){
        head=NULL;
        next=NULL;
    }
    };
    RowNode *newRowNode,*tempRowNode;
    RowNode* mainHead;
    Mat();
    void display();
};

Mat::Mat(){
    int rows,columns,temp;
    mainHead=NULL;
    cout<<"\nEnter the number of rows and columns"<<endl;
    cin>>rows>>columns;
    cout<<"\nEnter the array elements one by one"<<endl;
    for(int i=0;i<rows;i++){
        newRowNode=new RowNode;
        if(mainHead==NULL)
            tempRowNode=mainHead=newRowNode;
        else{
            tempRowNode->next=newRowNode;
            tempRowNode=newRowNode;
        }
        for(int j=0;j<columns;j++){
            cin>>temp;
            newColumnNode=new ColumnNode;
            newColumnNode->data=temp;
            if(tempRowNode->head==NULL){
                tempColumnNode=tempRowNode->head=newColumnNode;
            }else{
                tempColumnNode->next=newColumnNode;
                tempColumnNode=newColumnNode;
            }
        }
    }
}

void Mat::display(){
    tempRowNode=mainHead;
    while(tempRowNode!=NULL){
        tempColumnNode=tempRowNode->head;
        while(tempColumnNode!=NULL){
            cout<<tempColumnNode->data<<" ";
            tempColumnNode=tempColumnNode->next;
        }
        tempRowNode=tempRowNode->next;
        cout<<endl;
    }
}

int main(){
    Mat m1;
    cout<<"\n\n\nThe entered matrix is "<<endl;
    m1.display();
    return 0;
}



