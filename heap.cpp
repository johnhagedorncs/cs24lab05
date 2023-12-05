// heap.cpp
// Diba Mirza
#include "heap.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Heap::push(int value) {
    vdata.push_back(value);
    heapifyUp(vdata.size() - 1);
}

void Heap::pop() {
    if (!vdata.empty()) {
        vdata[0] = vdata.back();
        vdata.pop_back();
        heapifyDown(0);
    }
}

int Heap::top() const {
    if (!vdata.empty()) {
        return vdata.front();
    } else {
        return 0;
    }
}

bool Heap::empty() const {
    return vdata.empty();
}

void Heap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (vdata[index] < vdata[parentIndex]) {
            std::swap(vdata[index], vdata[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void Heap::heapifyDown(int index) {
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < vdata.size() && vdata[leftChild] < vdata[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < vdata.size() && vdata[rightChild] < vdata[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(vdata[index], vdata[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}