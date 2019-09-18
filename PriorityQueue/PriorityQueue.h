//
// Created by Cezary Borowski on 2019-09-18.
//

#ifndef HEAP_PRIORITYQUEUE_H
#define HEAP_PRIORITYQUEUE_H


#include <string>
#include <vector>

struct entry {
    unsigned long key;
    std::string value;
};

class PriorityQueue {
private:
    std::vector<entry> entries;

    void validate();

public:
    void add(unsigned long key, std::string value);
    unsigned long size();
    bool empty();
    entry pop();
    entry get();
};


#endif //HEAP_PRIORITYQUEUE_H
