#include "stack.h"
#include <iostream>

Stack::Stack() {
    this->firstNode = NULL;
}

Stack::~Stack() {

}

void Stack::push(ItemType item) {
    //create new item
    NodeType *newNode = new NodeType;
    newNode->item = item;
    newNode->next = NULL;
    newNode->previous = NULL;

    if(this->isEmpty()) {
        //put new item in the first position, if it is empty
        this->firstNode = newNode;
        this->lastNode = newNode;
        //null<-a->null
    } else {        
        //calculate references
        this->lastNode->next = newNode;
        newNode->previous = this->lastNode;
        //allocate new node in the last position
        this->lastNode = newNode;
    }

}

bool Stack::isEmpty() const {
    return this->firstNode == NULL;
}

bool Stack::isFull() const {
    NodeType *testLocation;

    //try to allocate, if it is not possible it means the memory is full
    try {
        testLocation = new NodeType;
        delete testLocation;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    }
}

ItemType Stack::pop() {
    if(this->isEmpty()) {
        return (char) NULL;
    }


    ItemType popped = this->lastNode->item;

    NodeType *nodeToPop = this->lastNode;


    bool uniqueElement = this->lastNode == this->firstNode;
    if(uniqueElement){
        //empty the stack
        this->lastNode = NULL;
        this->firstNode = NULL;
    } else {
        //dealocate the last position
        this->lastNode = this->lastNode->previous;
        this->lastNode->next = NULL;
    }

    delete nodeToPop;

    return popped;
}