// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

/*
 * The linked list is the primary data structure used in the assignment.
 *
 * It stores each character that was typed by the user, character by character.
 * New line characters, and spaces are also stored appropriately.
 *
 * Non-printable characters were filtered out in "main.cpp"
 */

class Linked_list {
    Node* head;

public:
    // Constructor
    Linked_list();

    // Destructor
    ~Linked_list();

    // Function that frees memory
    void delList();

    // Return the head of the linked list
    Node* getHead() const;

    // Return if the list is empty or not
    bool isEmpty() const;

    // Insert a letter at the beginning
    void insertAtBeginning(char letter);

    // Insert a letter at the end
    void insertAtEnd(char letter);

    // Insert a letter at a certain position
    void insertAtPosition(char letter, int position);

    // Delete a letter from the beginning
    void deleteFromBeginning();

    // Delete a letter from the end
    void deleteFromEnd();

    // Delete a letter at a certain position
    void deleteFromPosition(int position);

    // Display the contents of the linked list
    void display() const;
};

#endif //LINKED_LIST_H
