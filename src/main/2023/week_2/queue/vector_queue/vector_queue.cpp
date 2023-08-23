#include "../queue.h"
#include <iostream>

Queue::Queue(ItemType *pHolder, int capacity) {
    this->pHolder = pHolder;
    this->lenght = 0;
    this->first = 0;
    this->last = 0;
    this->count = 0;
    this->capacity = capacity;
    
    this->emptyQueue();
}

Queue::~Queue() {
    
}

void Queue::enqueue(ItemType item) {
    //verifica se está cheia
    if(this->isFull())
        throw std::runtime_error("Full queue");

    //enfileira
    this->pHolder[this->last] = item;

    //calcula ultima posicao da fila
    this->count++;
    this->last = this->count%capacity;

    //aumenta o tamananho da fila
    this->lenght++;
}

ItemType Queue::dequeue() {
    if(this->isEmpty())
        throw std::runtime_error("Dequeuing an empty queue!");

    //desenfileira o primeiro
    ItemType dequeued = this->pHolder[this->first];
    this->pHolder[this->first] = (char) NULL;
    this->lenght--;

    //calcula o primeiro da fila
    this->first++;
    this->first = this->first%capacity;

    return dequeued;
}

bool Queue::isFull() const {
    if (this->lenght >= this->capacity)
        return true;
    
    return false;
}

void Queue::emptyQueue() const {
    for(int i = 0; i < this->capacity; i++)
        this->pHolder[i] = (char) NULL;
}

bool Queue::isEmpty() const {
    bool empty = true;

    //verifica se a fila está inicializada -> não é necessário, porém para fins didáticos deixei aqui.
    for(int i = 0; i < this->capacity; i++) {
        if(this->pHolder[i] != (char) NULL)
            return false;
    }

    return empty && this->lenght == 0;
}
