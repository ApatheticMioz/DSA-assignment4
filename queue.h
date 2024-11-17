#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include "Node.h"

class Queue {
    Node* front;
    Node* rear;

public:
    Queue();

    ~Queue();

    bool isEmpty() const;

    void enqueue(char letter);

    void dequeue();

    char getFront() const;

    char getRear() const;
};

#endif //QUEUE_H
