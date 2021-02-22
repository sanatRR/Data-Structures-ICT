//Copyright (c) 2021 Sanat Raorane
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#define N 50

class student{
    private:
        char name[N],grade;
        int rollNo,num;
    public:
        /**
        *Function to read an array of student objects
        *parameter arr:array of student objects, num:number of objects
        */
        void read(student arr[],int num);
        /**
        *Function to display an array of student objects
        *parameter arr:array of student objects, num:number of objects
        */
        void display(student arr[],int num);
        /**
        *Function to sort an array of student objects
        *parameter arr:array of student objects, num:number of objects
        */
        void sortArr(student arr[],int num);
};

#endif // STUDENT_H_INCLUDED
