#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node {
public:
    char letter;
    Node* next;

    explicit Node(char letter);
};

class linked_list {
    Node* head;

public:
    linked_list();

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
