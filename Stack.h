#ifndef STACK_H
#define STACK_H

#include "NodeStr.h"

class Stack {
    NodeStr* head;
    int states;

public:
    Stack();

    ~Stack();

    bool isEmpty() const;

    void push(const string& state);

    void pop();

    string peek() const;
};

#endif //STACK_H
