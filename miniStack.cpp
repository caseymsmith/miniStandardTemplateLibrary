#include <iostream>
#include "miniStack.h"
using namespace std;


template<class DataType>
miniStackVT<DataType>::miniStackVT(int variable) {
    content.reserve(variable);
}

template<class DataType>
miniStackVT<DataType>::~miniStackVT() {
    //delete content
}

template<class DataType>
int miniStackVT<DataType>::size() const {
    return content.size();
}

template<class DataType>
bool miniStackVT<DataType>::IsEmpty() const {
    if (content.empty())
        return true;
    else
        return false;
}

template<class DataType>
void miniStackVT<DataType>::Push(DataType const &item) {
    content.push_back(item);
}

template<class DataType>
void miniStackVT<DataType>::PrintStack() const {
    for (int i = 0; i < content.size(); i++)
        cout << content[i] << " ";
}

template<class DataType>
DataType miniStackVT<DataType>::Pop() {
    if (!IsEmpty()) {
        DataType temp = content.back();
        content.pop_back();
        return temp;
    }

    else
        throw emptyStackException();
}

template<class DataType>
DataType miniStackVT<DataType>::TopStack() const {
    if(!IsEmpty())
        return content.back();
    else
        throw emptyStackException();
}


//////////////////////////////////////////////////////////////////


template<class DataType>
miniStackLT<DataType>::miniStackLT(int variable) {
    content.resize(variable);
}

template<class DataType>
miniStackLT<DataType>::~miniStackLT() {
    //delete content;
}

template<class DataType>
int miniStackLT<DataType>::size() const {
    return content.size();
}

template<class DataType>
bool miniStackLT<DataType>::IsEmpty() const {
    if (content.empty())
        return true;
    else
        return false;
}

template<class DataType>
void miniStackLT<DataType>::Push(DataType const &item) {
    content.push_back(item);
}

template<class DataType>
void miniStackLT<DataType>::PrintStack() const {
    typename std::list<DataType>::const_iterator iter;

    for (iter = content.begin(); iter != content.end(); iter++)
        cout << *iter << " ";
}

template<class DataType>
DataType miniStackLT<DataType>::Pop() {
    if (!IsEmpty()) {
        DataType temp = content.back();
        content.pop_back();
        return temp;
    }
    else
        throw emptyStackException();
}

template<class DataType>
DataType miniStackLT<DataType>::TopStack() const {
    if(!IsEmpty())
        return content.back();
    else
        throw emptyStackException();
}

//////////////////////////////////////////////////////////////////

template <class DataType>
miniStackDA<DataType>::miniStackDA(int variable) {
    capacity=variable;
    content=new DataType[variable];
}

template <class DataType>
miniStackDA<DataType>::~miniStackDA() {
    delete [] content;
}

template <class DataType>
int miniStackDA<DataType>::size() const {
    return NodeCount;
}

template <class DataType>
bool miniStackDA<DataType>::IsEmpty() const {
    return NodeCount==0;
}

template <class DataType>
void miniStackDA<DataType>::Push(const DataType& item){
    if(atCapacity())
        resize();

    content[NodeCount]=item;
    NodeCount++;
}

template <class DataType>
void miniStackDA<DataType>::PrintStack() const {

    for(int i=NodeCount-1; i>= 0; i--)
        cout << content[i] << " ";
}

template <class DataType>
DataType miniStackDA<DataType>::Pop() {
    if (!IsEmpty()) {
        DataType temp = content[0];
        for (int i = 1; i < NodeCount; i++)
            content[i - 1] = content[i];
        NodeCount--;
        return temp;
    }

    else
        throw emptyStackException();
}

template <class DataType>
bool miniStackDA<DataType>::atCapacity() const {
    return NodeCount==capacity-1;
}

template <class DataType>
void miniStackDA<DataType>::resize() {
    DataType* temp;
    int tempCapacity=(int)(capacity*1.5)+1;
    temp=new DataType[tempCapacity];

    for(int i=0; i<capacity; i++)
        temp[i]=content[i];

    delete [] content;
    content=temp;
    capacity=tempCapacity;
}

template <class DataType>
DataType miniStackDA<DataType>::TopStack() const {
    if(!IsEmpty())
        return content[NodeCount - 1];
    else
        throw emptyStackException();
}
