// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#ifndef NOTEPAD_H
#define NOTEPAD_H

#include "Linked_list.h"
#include "Queue.h"
#include "Stack.h"
#include "AVL_tree.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

// Implementation of the notepad class, which provides the overall functionality.

class Notepad {
    AVL_tree tree;
    Linked_list list;
    Queue word;
    Stack notepadHistory;
    Stack wordHistory;

    // Function to count lines from a given file
    int countLines(const string& filename);

    /* Function to recursively build an AVL Tree from an
     * array, which has merge sort applied to itself
     *
     * Array is built from the middle, which is chosen as the root, then subdivided
     * into arrays, both of lengths that divide by 2.
     */
    TreeNode* buildAVLFromArray(string* arr, int start, int end);

    // The array is loaded from the dictionary provided
    void loadArray(const string& filename, string* arr, int size);

    // The dictionary is created, which calls the previous functions
    void loadDict(TreeNode* &treeRoot);

    /*
     * The words, if they don't exist in the dictionary provided, are spelt check for accuracy
     * The following techniques are used:
     *      1. Letter Substitution:
     *          Every letter is switched to another letter, and then it is checked if the new word
     *          exists in the dictionary or not.
     *
     *      2. Letter Omission:
     *          Attempts are made to omit each letter, one by one, and then it is checked if the new
     *          word exists in the dictionary or not.
     *
     *      3. Letter Insertion:
     *          Attempts are made to insert letter at every possible position, then it is checked
     *          if the new word exists in the dictionary or not.
     *
     *      4. Letter Reversal:
     *          Pairs of letters are reversed, and then it is seen if the new word exists in the
     *          dictionary or not.
     *
     *            --If it exists, we return the new word
     *            --If it does not exist we, return "Not found"
     */
    void spellCheck();

    // Leading and trailing whitespaces/newline characters are removed
    string strip(const string& str);

    // Linked list is converted to a string
    string listToString();

    // Queue is converted to a string
    string queueToString();

    // String is converted to a Queue
    void stringToQueue(const string& str);

public:
    Notepad();

    // Dictionary is loaded
    void initialiseDict();

    // Note pad is displayed
    void display() const;

    // File of "filename" is loaded
    void loadFile(const string& filename);

    // Current note pad is saved to "save.txt"
    void saveFile();

    // Backspace is emulated, deleting the last character typed
    void deleteLast();

    // Last operation is undone
    void undo();

    // User input character is added to the notepad, inserting at the end of the linked list
    void writeCh(char ch);
};

#endif //NOTEPAD_H
