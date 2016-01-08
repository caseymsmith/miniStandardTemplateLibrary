#ifndef MINISTACK_H
#define MINISTACK_H

#include <vector>
#include <list>

using namespace std;

template<class DataType>
class miniStackVT {
private:
    vector<DataType> content;
    int NodeCount;        //number of node in the stack

public:
    miniStackVT(int);        //constructor create a stack with size
    ~miniStackVT();          //destructor
    int size() const;        //return the number of elements in the stack
    bool IsEmpty() const;    //check empty stack for pop
    void Push(const DataType &);    //push a node in the stack
    void PrintStack() const;     //print all stack content (top to bottom)
    DataType Pop();          //Pop an element from the top of the stack.
    //issue exception if the stack is empty.

    DataType TopStack() const;   //return Data from top of the stack.

};

class emptyStackException: public exception{
    public: virtual const char* what() const throw(){
        return "Error: The stack is empty";
    }
};


template<class DataType>
class miniStackLT {
private:
    list<DataType> content;
    int NodeCount;        //number of node in the stack

public:
    miniStackLT(int);        //constructor create a stack with size
    ~miniStackLT();          //destructor
    int size() const;        //return the number of elements in the stack
    bool IsEmpty() const;    //check empty stack for pop
    void Push(const DataType &);    //push a node in the stack
    void PrintStack() const;     //print all stack content (top to bottom)
    DataType Pop();          //Pop an element from the top of the stack.
    //issue exception if the stack is empty.

    DataType TopStack() const;   //return Data from top of the stack.

};


template<class DataType>
class miniStackDA {
private:
    DataType* content;
    int NodeCount, capacity;        //number of node in the stack
    bool atCapacity() const;
    void resize();

public:
    miniStackDA(int=8);        //constructor create a stack with size
    ~miniStackDA();          //destructor
    int size() const;        //return the number of elements in the stack
    bool IsEmpty() const;    //check empty stack for pop
    void Push(const DataType &);    //push a node in the stack
    void PrintStack() const;     //print all stack content (top to bottom)
    DataType Pop();          //Pop an element from the top of the stack.
    //issue exception if the stack is empty.

    DataType TopStack() const;   //return Data from top of the stack.

};


//#include "miniStack.cpp"

#endif
