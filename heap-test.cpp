#include "heap.h"
#include <iostream>
#include <string>
#include <vector>
#include <functional>

int main() {
    // Testing min-heap
    Heap<int> minHeap;
    std::cout << "Testing min-heap:" << std::endl;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(5);
    std::cout << "Size: " << minHeap.size() << std::endl;
    while (!minHeap.empty()) {
        std::cout << "Top: " << minHeap.top() << std::endl;
        minHeap.pop();
    }

    // Testing max-heap using std::greater<T>
    Heap<int, std::greater<int>> maxHeap;
    std::cout << "\nTesting max-heap:" << std::endl;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(1);
    maxHeap.push(5);
    std::cout << "Size: " << maxHeap.size() << std::endl;
    while (!maxHeap.empty()) {
        std::cout << "Top: " << maxHeap.top() << std::endl;
        maxHeap.pop();
    }

    return 0;
}