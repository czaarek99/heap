//
// Created by Cezary Borowski on 2019-09-18.
//

#include "PriorityQueue.h"
#include <algorithm>

void PriorityQueue::add(unsigned long key, std::string value) {
    const entry e{
        .key = key,
        .value =  value
    };

    this->entries.push_back(e);

    if(this->entries.size() > 1) {
        unsigned long newIndex = this->entries.size() - 1;

        while(true) {
            unsigned long parentIndex = newIndex / 2;

            if(this->entries[parentIndex].key > this->entries[newIndex].key) {
                std::swap(this->entries[parentIndex], this->entries[newIndex]);
            } else {
                break;
            }

            newIndex = parentIndex;
        }
    }
}

entry PriorityQueue::get() {
    this->validate();
    return this->entries.front();
}

entry PriorityQueue::pop() {
    this->validate();

    const entry popped = this->entries.front();

    this->entries[0] = this->entries.back();
    this->entries.pop_back();

    const unsigned long maxIndex = this->entries.size() - 1;
    unsigned long index = 0;

    while(true) {
        entry parent = this->entries[index];

        unsigned long firstChildIndex = index * 2;
        unsigned long secondChildIndex = index * 2 + 1;

        if (firstChildIndex > maxIndex){
            break;
        }

        entry child1 = this->entries[firstChildIndex];
        bool hasSecondChild = secondChildIndex <= maxIndex;

        if(hasSecondChild) {
            entry child2 = this->entries[secondChildIndex];

            if(parent.key > child1.key || parent.key > child2.key) {
                unsigned long min = std::min(child1.key, child2.key);

                if (child1.key == min) {
                    std::swap(this->entries[index], this->entries[firstChildIndex]);
                    index = firstChildIndex;
                } else if(child2.key == min) {
                    std::swap(this->entries[index], this->entries[secondChildIndex]);
                    index = secondChildIndex;
                }
            } else {
                break;
            }
        } else if(parent.key > child1.key){
            std::swap(this->entries[index], this->entries[firstChildIndex]);
            index = firstChildIndex;
        } else {
            break;
        }
    }

    return popped;
}

void PriorityQueue::validate() {
    if (this->empty()) {
        throw std::out_of_range("Queue is empty");
    }
}

bool PriorityQueue::empty() {
    return this->entries.empty();
}

unsigned long PriorityQueue::size() {
    return this->entries.size();
}
