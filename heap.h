// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza
#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>
using namespace std;

class Heap{

 public:
   void push(int value); // insert value; //duplicates are allowed
   void pop(); // delete the min element 
   int top() const;
   bool empty() const;

   void heapifyUp(int index);
   void heapifyDown(int index);
    
 private:
   vector<int> vdata; //store the binary heap tree as a dynamic array
};

#endif