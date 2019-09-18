#include <iostream>
#include "PriorityQueue/PriorityQueue.h"

int main() {
    PriorityQueue queue;

    entry e = queue.pop();

    std::cout << e.value << std::endl;

    return 0;
}