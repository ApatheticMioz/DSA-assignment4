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

class Notepad {
    AVL_tree tree;
    Linked_list list;
    Queue word;
    Stack notepadHistory;
    Stack wordHistory;

    int countLines(const string& filename);

    TreeNode* buildAVLFromArray(string* arr, int start, int end);

    void loadArray(const string& filename, string* arr, int size);

    void loadDict(TreeNode* &treeRoot);

    void spellCheck();

    string listToString();

    string queueToString();

    void stringToQueue(const string& str);

public:
    Notepad();

    void initialiseDict();

    void display() const;

    void loadFile(const string& filename);

    void saveFile();

    void deleteLast();

    void undo();

    void writeCh(char ch);
};

#endif //NOTEPAD_H
