// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

/*
 * A queue was used to keep track of the latest word being entered by the user
 *
 * The FIFO principle of a queue helped me decide on that.
 */

class Queue {
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Function to free the allocated memory
    void clear();

    // Deep copy constructor
    Queue(const Queue& other);

    // Returns if the queue is empty or not
    bool isEmpty() const;

    // Adds a letter to the queue
    void enqueue(char letter);

    // Removes a letter from the queue
    void dequeue();

    // Returns the front most letter from the queue
    char getFront() const;

    // Returns the rear most letter from the queue
    char getRear() const;
};

#endif //QUEUE_H
