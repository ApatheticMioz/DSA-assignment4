// Data Structures

#ifndef STACK_H
#define STACK_H

#include "NodeStr.h"

/*
 * The stack has been used to preserve the history of the notepad
 *
 * It has been primarily utilised to manage the undo function of the notepad.
 */

class Stack {
    NodeStr* head;
    int states;

public:
    // Constructor
    Stack();

    // Destructor
    ~Stack();

    // Returns if the stack is empty or not
    bool isEmpty() const;

    // Pushes a string to the stack
    void push(const string& state);

    // Pops a string from the stack
    void pop();

    // Returns the topmost value from the stack
    string peek() const;
};

#endif //STACK_H
