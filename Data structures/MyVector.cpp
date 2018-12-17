#include "MyVector.h"
#include <iostream>

MyVector::MyVector() {
    MyVector(16);
}

MyVector::MyVector(int size) {
    // Capacity start from 2^4 elements
    int capacity = 16;
    while (capacity<size){
        capacity*=2;
    }
    assignMemory(capacity);
    _size = ca
}

// Free memory
MyVector::~MyVector(){
    delete [] _array;
    _array = NULL;
}

void MyVector::assignMemory(int capacity){
    this->_capacity = capacity;
    // Create a new dynamic array
    int* _newArray = new int[capacity]; 
    std::cout<<_newArray<<"\n";
    std::cout<<_array<<"\n";

    // Copy the old elements
    if (_size>0){
        for (int i=0; i<_size; i++){
            std::cout<<_size;
            *(_newArray+i) = *(_array+i);
        }
    }
    std::cout<<_size;
    // Assign for the others elements
    for (int i=_size; i<capacity; i++){
        *(_newArray+i) = 0;
    }
    std::cout<<_array;
    // Free memory of the old array
    delete [] _array;
    // Assign the new array to this->_array
    this->_array = _newArray;
    
}

void MyVector::push_back(int input){
    // If the size exceed the capacity
    if (_size>_capacity){
        // Double the capacity
        _capacity*=2;
        assignMemory(_capacity);
    }
    *(_array+_size) = input;
    _size++;
}

int MyVector::getElementAt(int index){
    if (index>=_size){
        std::cout<<"The index value exceed Vector's size ("<<_size<<")\n";
        throw;
    }
    return *(_array+index);
}

int MyVector::size(){
    return _size;
}

int MyVector::capacity(){
    return _capacity;
}

bool MyVector::is_empty(){
    if (_size>0)
        return true;
    return false;
}