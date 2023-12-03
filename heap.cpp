// heap.cpp
// Diba Mirza
#include "heap.h"
#include <iostream>
#include <vector>
using namespace std;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value); // Add value to end of the vector
  int index = vdata.size() - 1; // Index of the newly added element
  while (index > 0) {
    int parentIndex = (index - 1) / 2;
    if (vdata[index] < vdata[parentIndex]) {
        swap(vdata[index], vdata[parentIndex]);
        index = parentIndex; // Move up to parent index
    } else {
        break; // Heap property satisfied
    }
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop() {
  if (vdata.empty()) {
    return;
  }
  vdata[0] = vdata.back(); // Replace the root (min) element with last element
  vdata.pop_back(); // Remove last element
  int index = 0;
  while (true) { // fix tree
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;
    if (leftChild < vdata.size() && vdata[leftChild] < vdata[smallest]) {
      smallest = leftChild;
    } else if (rightChild < vdata.size() && vdata[rightChild] < vdata[smallest]) {
      smallest = rightChild;
    }
    if (smallest != index) {
      swap(vdata[index], vdata[smallest]);
      index = smallest; // Move down to smallest childs index
    } else {
      break;
    }
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (!vdata.empty()) {
    return vdata[0];
  } else {
    return 0;
  }
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty() {
    return vdata.empty();
}
    