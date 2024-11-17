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

    int countLines(const string& filename);

    TreeNode* buildAVLFromArray(string* arr, int start, int end);

    void loadArray(const string& filename, string* arr, int size);

    void loadDict(TreeNode* &treeRoot);

public:
    Notepad();

    void initialise();
};

#endif //NOTEPAD_H
