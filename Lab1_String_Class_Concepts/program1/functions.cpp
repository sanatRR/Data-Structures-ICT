//Copyright (c) 2021 Sanat Raorane
#include<iostream>
#include"stringhead.h"
#define N 100
using namespace std;

String::String(char arrayAL[]){
        int i=0;
        while(arrayAL[i]!='\0'){
            arrayA[i]=arrayAL[i]; //writing arrayAL[i++] gave error
            i++;
        }
        arrayA[i]='\0';
}

int String::length(){
    int num=0,i=0;
    while(arrayA[i++]!='\0'){
        num++;
    }
    return num;
}

char* String::stringConcat(char arrayB[]){
    static char result[N];  //declared static to ensure it stays in memory after function returns
    int i=0,j=0;
    while(arrayA[i]!='\0'){
        result[j++]=arrayA[i++];
    }
    i=0;
    while(arrayB[i]!='\0'){
        result[j++]=arrayB[i++];
    }
    result[j]='\0';
    return result;
}

int String::stringCompare(char arrayB[]){
    for(int i=0,j=0;arrayA[i]!='\0' && arrayB[j]!='\0';i++,j++){
        if(arrayA[i]>arrayB[j])
            return 1;
        else if(arrayA[i]<arrayB[j])
            return -1;
    }
    return 0;
}

void String::insertSubstring(char subString[],int pos){
    char temp[N];
    int i,j;
    if(pos>length()-1)
        cout<<"Invalid Position - No Operation Performed "<<endl;
    else{
        //Copy portion starting from pos to a temporary array
        for(i=pos,j=0;arrayA[i]!='\0';i++,j++)
            temp[j]=arrayA[i];
        temp[j]='\0';
        //Write the subString to the main Array
        for(i=pos,j=0;subString[j]!='\0';i++,j++){
            arrayA[i]=subString[j];
        }
        //Copy the temporary array back to Main array
        j=0;
        while(temp[j]!='\0'){
            arrayA[i]=temp[j];
            i++;
            j++;
        }
        arrayA[i]='\0';
    }
}

int String::subSearch(char target[]){
    int temp,i,j;
    for(i=0;arrayA[i]!='\0';i++)
    {
        /*
        *If first character of substring found
        *then proceed to match next characters
        */
        if(arrayA[i]==target[0])
        {
            temp=i;
            for(j=0;target[j]!='\0' && arrayA[i]!='\0';j++,i++)
            {
                /*
                *In case of mismatch, return
                *to index where matching started
                */
                if(target[j]!=arrayA[i])
                {
                    i=temp;
                    break;
                }
            }
            /*
            *Reaching end of target indicates
            *string found, so return index
            */
            if(target[j]=='\0')
                return temp;
        }
    }
    //Return -1 if true not returned
    return -1;
}

void String::deleteSubstring(char delSub[]){
    /*
    *ind has index where the String to
    *be deleted is present
    */
    int ind=subSearch(delSub),tempind;
    if(subSearch(delSub)!=-1)
    {
        /*
        *ind!=-1, hence subString
        *exists
        */
        int i,j;
        char temp[N];
        /*
        *Copy portion before the
        *delSub to temp
        */
        for(i=0;i<ind;i++)
                temp[i]=arrayA[i];
        tempind=i;
        /*
        *Move i beyond the subString to be
        *deleted
        */
        for(j=0;delSub[j]!='\0';i++,j++){}

        /*
        *Copy portion after delSub to
        *temp
        */
        for(j=tempind;arrayA[i]!='\0';i++,j++)
        {
            temp[j]=arrayA[i];
        }
        temp[i]='\0';
        /*
        *Copy temp to
        *main array arrayA
        */
        for(i=0;temp[i]!='\0';i++)
        {
            arrayA[i]=temp[i];
        }
        arrayA[i-1]='\0';
        //'\0' is added to mark end of String
    }
    else
        cout<<"\nString not found";
}
