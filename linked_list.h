#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

class Linked_list {
    Node* head;

public:
    Linked_list();

    ~Linked_list();

    bool isEmpty() const;

    void insertAtBeginning(char letter);

    void insertAtEnd(char letter);

    void insertAtPosition(char letter, int position);

    void deleteFromBeginning();

    void deleteFromEnd();

    void deleteFromPosition(int position);

    void display() const;
};

#endif //LINKED_LIST_H
