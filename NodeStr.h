// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#ifndef NODESTR_H
#define NODESTR_H

#include <string>
using namespace std;

/*
 * This node class was created to store string nodes
 * It has been utilized in a stack, to store words
 */

class NodeStr {
public:
    string word;
    NodeStr* next;

    // Constructor
    explicit NodeStr(const string& word);
};

#endif //NODESTR_H
