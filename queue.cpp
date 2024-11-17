#include "queue.h"

Node::Node(const char letter) : letter(letter), next(nullptr) {}

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue:: ~Queue() {
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
