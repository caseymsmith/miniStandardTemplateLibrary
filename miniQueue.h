#ifndef MINIQUEUE_H
#define MINIQUEUE_H

#include <vector>
#include <list>

using namespace std;

template<class DataType>
class miniQueueVT {
private:
    vector<DataType> content;
    int QueueCnt;        //element count in a Queue

public:
    miniQueueVT(int=0);        //class constructor - initialize variables
    ~miniQueueVT();          //class destructor - return memory used by queue elements
    void enqueue(const DataType &);      //add an item to the back of the queue
    DataType dequeue();         //remove the first item from the queue and return its value
    DataType front() const;     //return the value of the front item in the queue
    void PrintQueue() const;    //print all queue content(front to back)
    bool IsEmpty() const;       //returns true if there are no elements in the queue
    int size() const;           //return the number of elements in the queue

};


class emptyQueueException: public exception{
    public: virtual const char* what() const throw(){
        return "Error: The queue is empty";
    }
};


template<class DataType>
class miniQueueLT {
private:
    list<DataType> content;
    int QueueCnt;        //element count in a Queue

public:
    miniQueueLT(int=0);        //class constructor - initialize variables
    ~miniQueueLT();          //class destructor - return memory used by queue elements
    void enqueue(const DataType &);      //add an item to the back of the queue
    DataType dequeue();         //remove the first item from the queue and return its value
    DataType front() const;     //return the value of the front item in the queue
    void PrintQueue() const;    //print all queue content(front to back)
    bool IsEmpty() const;       //returns true if there are no elements in the queue
    int size() const;           //return the number of elements in the queue

};

template<class DataType>
class miniQueueDA {
private:
    DataType* content;
    int QueueCnt, capacity;         //element count in a Queue
    bool atCapacity() const;        //checks to see if the array is at capacity
    void resize();                  //increases the size of the array

public:
    miniQueueDA(int=8);        //class constructor - initialize variables
    ~miniQueueDA();          //class destructor - return memory used by queue elements
    void enqueue(const DataType &);      //add an item to the back of the queue
    DataType dequeue();         //remove the first item from the queue and return its value
    DataType front() const;     //return the value of the front item in the queue
    void PrintQueue() const;    //print all queue content(front to back)
    bool IsEmpty() const;       //returns true if there are no elements in the queue
    int size() const;           //return the number of elements in the queue

};

//class outOfMemoryError {
//public:
//    string what() const {
//        return "Error: Out of memory.";
//    }
//};

//#include "miniQueue.cpp"

#endif
