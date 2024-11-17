#include "Stack.h"

Node::Node(const char letter) : letter(letter), next(nullptr) {}

Stack::Stack() : head(nullptr) {}

Stack::~Stack() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool Stack::isEmpty() const {
    return head == nullptr;
}

void Stack::push(const char letter) {
    Node* newNode = new Node(letter);

    newNode->next = head;
    head = newNode;
}

void Stack::pop() {
    if (isEmpty()) {
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

char Stack::peek() const {
    if (isEmpty())
        return head->letter;

    return '\0';
}