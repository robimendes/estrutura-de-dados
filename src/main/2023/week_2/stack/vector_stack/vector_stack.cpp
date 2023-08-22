#include "vector_stack.h"
#include <cstddef>

VectorStack::VectorStack(ItemType pHolder[], int capacity) {
    this->length = 0;
    this->holderCapacity = capacity;

    for (int i = 0; i < capacity; i++) {
        pHolder[i] = (char) NULL;
    }

    this->pHolder = pHolder;
}

VectorStack::~VectorStack() {

}

void VectorStack::push(ItemType item) {
    if(!this->isFull()) {
        this->pHolder[this->length] = item;
        this->length++;
    }
}

ItemType VectorStack::pop() {
    if(this->isEmpty()) {
        throw std::runtime_error("empty stack!");
    }

    int lastPosition = this->length-1;
    ItemType popped = this->pHolder[lastPosition];
    this->pHolder[lastPosition] = (char) NULL;
    this->length--;

    return popped;
}

bool VectorStack::isEmpty() const {
    return this->length == 0;
}

bool VectorStack::isFull() const {
    return this->length >= this->holderCapacity;
}
