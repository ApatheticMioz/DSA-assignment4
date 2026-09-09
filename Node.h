// Data Structures

#ifndef NODE_H
#define NODE_H

// Node class used by any datastructure that required letter by letter nodes

class Node {
public:
    char letter;
    Node* next;

    // Constructor
    explicit Node(char letter);
};

#endif //NODE_H
