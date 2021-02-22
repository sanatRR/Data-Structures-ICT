//Copyright (c) 2021 Sanat Raorane
#ifndef SPARSEHEAD_H_INCLUDED
#define SPARSEHEAD_H_INCLUDED

class sparseHead{
private:
    /*
    *m: no of rows in matrix
    *n: no of columns in matrix
    *nonzeroct: no of non-zero elements in matrix
    */
    int m,n,nonzeroct;
    class triples{
    public:
         int row,column,element;
    };
    //Triples array
    triples t[100];
public:
    /**
    *Constructor for sparseHead class
    */
    sparseHead();
    /**
    *Function to display the triple array
    */
    void display();
    /**
    *Function to take fast Transpose of
    *a triples array
    */
    void fTranspose();
    /**
    *Function to initialize triples array using
    *sparse m x n matrix
    */
    void convert();
};


#endif // SPARSEHEAD_H_INCLUDED
