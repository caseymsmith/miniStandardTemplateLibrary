#include<iostream>
#include "miniQueue.h"
using namespace std;


template<class DataType>
miniQueueVT<DataType>::miniQueueVT(int variable) {
    content.reserve(variable);
}

template<class DataType>
miniQueueVT<DataType>::~miniQueueVT() {
    //delete content;
}

template<class DataType>
void miniQueueVT<DataType>::enqueue(DataType const &item) {
    content.push_back(item);
}

template<class DataType>
DataType miniQueueVT<DataType>::dequeue() {
    DataType temp;

    if(content.empty())
        throw emptyQueueException();

    temp = content.front();
    content.pop_back();
    return temp;
}

template<class DataType>
DataType miniQueueVT<DataType>::front() const{
    if(content.empty())
        throw emptyQueueException();

    return content.front();
}

template<class DataType>
void miniQueueVT<DataType>::PrintQueue() const {
    for (int i = 0; i < content.size(); i++)
        cout << content[i] << " ";
}

template<class DataType>
bool miniQueueVT<DataType>::IsEmpty() const {
    return content.empty();
}

template<class DataType>
int miniQueueVT<DataType>::size() const {
    return content.size();
}


//////////////////////////////////////////////////////////////////


template<class DataType>
miniQueueLT<DataType>::miniQueueLT(int variable) {
    content.resize(variable);
}

template<class DataType>
miniQueueLT<DataType>::~miniQueueLT() {
    //delete content;
}

template<class DataType>
void miniQueueLT<DataType>::enqueue(DataType const &item) {
    content.push_back(item);
}

template<class DataType>
DataType miniQueueLT<DataType>::dequeue() {
    DataType temp;
    if(content.empty())
        throw emptyQueueException();

    temp = content.front();
    content.pop_back();
    return temp;

}

template<class DataType>
DataType miniQueueLT<DataType>::front() const{
    if(content.empty())
        throw emptyQueueException();

    return content.front();
}

template<class DataType>
void miniQueueLT<DataType>::PrintQueue() const {
    typename std::list<DataType>::const_iterator iter;
    for (iter = content.begin(); iter != content.end(); iter++)
        cout << *iter << " ";
}

template<class DataType>
bool miniQueueLT<DataType>::IsEmpty() const {
    return content.empty();
}

template<class DataType>
int miniQueueLT<DataType>::size() const {
    return content.size();
}


//////////////////////////////////////////////////////////////////


template <class DataType>
miniQueueDA<DataType>::miniQueueDA(int variable) {
    capacity=variable;
    content=new DataType[variable];

}

template <class DataType>
miniQueueDA<DataType>::~miniQueueDA() {
    delete [] content;
    //need [] because content is an array
}

template <class DataType>
void miniQueueDA<DataType>::enqueue(DataType const & item) {
    if(atCapacity()){
        resize();
    }

    content[QueueCnt]=item;
    QueueCnt++;
}

template <class DataType>
bool miniQueueDA<DataType>::atCapacity() const {
        return QueueCnt==capacity-1;
}

template <class DataType>
void miniQueueDA<DataType>::resize() {

    DataType* temp;
    int tempCapacity=(int)(capacity*1.5)+1;
    temp=new DataType[tempCapacity];

//    if(temp!=NULL){

        for(int i=0; i< capacity; i++)
            temp[i]=content[i];

        delete [] content;
        content=temp;
        capacity=tempCapacity;
//    }
//
//    else
//        throw outOfMemoryError();

}

template <class DataType>
DataType miniQueueDA<DataType>::dequeue() {
    if(!IsEmpty()) {
        DataType temp = content[0];
        for (int i = 1; i < QueueCnt; i++)
            content[i - 1] = content[i];
        QueueCnt--;
        return temp;
    }
    else
        throw emptyQueueException();
}

template <class DataType>
DataType miniQueueDA<DataType>::front() const {
    if(QueueCnt==0){
        throw emptyQueueException();
    }
    return content[0];
}

template <class DataType>
void miniQueueDA<DataType>::PrintQueue() const {
    for (int i=QueueCnt-1; i >= 0; i--)
    cout << content[i] << " ";
}

template <class DataType>
bool miniQueueDA<DataType>::IsEmpty() const {
    return QueueCnt==0;
}

template <class DataType>
int miniQueueDA<DataType>::size() const {
    return QueueCnt;
}
