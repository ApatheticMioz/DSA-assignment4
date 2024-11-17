// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#include "queue.h"
#include "Node.h"

// The documentation is provided in the header file "Queue.h"
// Comments/documentation is added in this source file where necessary

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue:: ~Queue() {
    clear();
}

Queue::Queue(const Queue& other) : front(nullptr), rear(nullptr) {
    if (other.isEmpty()) {
        return;
    }

    Node* current = other.front;
    while (current != nullptr) {
        enqueue(current->letter);
        current = current->next;
    }
}

void Queue::clear() {
    while (front) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

bool Queue::isEmpty() const {
    if (front == nullptr)
        return true;

    return false;
}

void Queue::enqueue(const char letter) {
    Node* newNode = new Node(letter);

    if (isEmpty()) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void Queue::dequeue() {
    if (isEmpty()) {
        return;
    }

    Node* temp = front;
    front = front->next;

    if (isEmpty()) {
        rear = nullptr;
    }

    delete temp;
}

char Queue::getFront() const {
    if (isEmpty()) {
        return '\0';
    }

    return front->letter;
}

char Queue::getRear() const {
    if (isEmpty()) {
        return '\0';
    }

    return rear->letter;
}
