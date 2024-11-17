// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#include "Stack.h"
#include "NodeStr.h"

// The documentation is provided in the header file "Stack.h"
// Comments/documentation is added in this source file where necessary

Stack::Stack() : head(nullptr), states(0) {}

Stack::~Stack() {
    while (head) {
        NodeStr* temp = head;
        head = head->next;
        delete temp;
    }
}

bool Stack::isEmpty() const {
    return head == nullptr;
}

void Stack::push(const string& word) {
    // If the stack size grows over the undo limit
    // Then the oldest element is removed
    if (states > 20) {
        NodeStr* current = head;
        NodeStr* prev = nullptr;

        while (current && current->next) {
            prev = current;
            current = current->next;
        }

        if (prev) {
            prev->next = nullptr;
            delete current;
        } else {
            delete head;
            head = nullptr;
        }

        states--;
    }

    auto* newNode = new NodeStr(word);
    states++;

    newNode->next = head;
    head = newNode;
}

void Stack::pop() {
    if (isEmpty()) {
        return;
    }

    NodeStr* temp = head;
    head = head->next;

    delete temp;
}

string Stack::peek() const {
    if (!isEmpty())
        return head->word;

    return "";
}