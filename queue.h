#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
    Node* front;
    Node* rear;

public:
    Queue();

    ~Queue();

    Queue(const Queue& other);

    bool isEmpty() const;

    void enqueue(char letter);

    void dequeue();

    char getFront() const;

    char getRear() const;

    void clear();
};

#endif //QUEUE_H
