#ifndef STACK_H
#define STACK_H

class Node {
public:
    char letter;
    Node* next;

    explicit Node(char letter);
};

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
