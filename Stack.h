#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include "Node.h"

class Stack {
    Node* head;

public:
    Stack();

    ~Stack();

    bool isEmpty() const;

    void push(char letter);

    void pop();

    char peek() const;
};

#endif //STACK_H
