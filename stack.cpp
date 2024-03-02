#include "stack.h"
#include <iostream>
#include <string>

int main() {
    Stack<int> sample;
    for (int i = 1; i < 4; i++){
      sample.push(i);
    }

    while (!sample.empty()) {
      std::cout << sample.top() << std::endl;
      sample.pop();
    }
    return 0;
}