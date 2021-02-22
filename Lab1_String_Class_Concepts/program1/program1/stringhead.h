#ifndef STRINGHEAD_H_INCLUDED
#define STRINGHEAD_H_INCLUDED
#define N 100

class String{
public:
    char arrayA[N]; //Max size 100
    /**
    *Function to find length of character array
    *returns int: The length of passed array
    */
    int length();
    /**
    *Function to concatenate two character arrays
    *parameter arrayB: The second character array
    *returns char*: A pointer to the concatenated array
    */
    char* stringConcat(char arrayB[]);
    /**
    *Function to compare strings on ASCII value basis
    *parameter arraySecond: The second character array
    *returns int -1:first<second, 0:first==second, 1:first>second
    */
    int stringCompare(char arraySecond[]);
    /**
    *Function to insert a Substring in a given String
    *parameter subString: The subString to be inserted, pos: The position of insertion (pos>length-1)
    */
    void insertSubstring(char subString[],int pos);
    /**
    *Function to search for a Substring in a given string
    *parameter target: The substring to be searched
    *returns index:If substring found, -1:If substring not found
    */
    int subSearch(char target[]);
    /**
    *Function to delete a Substring from a given String
    *parameter delSub: The subString to be deleted
    *This function is dependent on subSearch function
    */
    void deleteSubstring(char delSub[]);
    /**
    *A public constructor for String Class
    */
    String(char arrayA[]);
};



#endif // STRINGHEAD_H_INCLUDED
