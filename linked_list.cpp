#include "Linked_list.h"
#include <iostream>

using namespace std;

Node::Node(const char letter) : letter(letter), next(nullptr) {}

Linked_list::Linked_list() : head(nullptr) {}

Linked_list::~Linked_list() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool Linked_list::isEmpty() const {
    return head == nullptr;
}

void Linked_list::insertAtBeginning(const char letter) {
    auto newNode = new Node(letter);
    newNode->next = head;
    head = newNode;
}

void Linked_list::insertAtEnd(const char letter) {
    auto newNode = new Node(letter);

    if (isEmpty()) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void Linked_list::insertAtPosition(const char letter, const int position) {
    if (position < 1) {
        return;
    }

    if (position == 1) {
        insertAtBeginning(letter);
        return;
    }

    auto* newNode = new Node(letter);

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp; i++) {
        temp = temp->next;
    }

    if (!temp) {
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void Linked_list::deleteFromBeginning() {
    if (isEmpty()) {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void Linked_list::deleteFromEnd() {
    if (isEmpty()) {
        return;
    }

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void Linked_list::deleteFromPosition(const int position) {
    if (position < 1) {
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void Linked_list::display() const {
    if (isEmpty()) {
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp->letter;
        temp = temp->next;
    }
}
