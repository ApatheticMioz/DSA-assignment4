#include "Notepad.h"
#include "algorithms.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

Notepad::Notepad() = default;

int Notepad::countLines(const string &filename) {
    ifstream file(filename);
    string word;

    int count = 0;

    while (getline(file, word)) {
        count++;
    }

    file.close();

    return count;
}

void Notepad::loadArray(const string &filename, string *arr, int size) {
    ifstream file(filename);
    string word;

    int index = 0;

    while (getline(file, word) && index < size) {
        arr[index++] = word;
    }

    file.close();
}

TreeNode *Notepad::buildAVLFromArray(string *arr, int start, int end) {
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = buildAVLFromArray(arr, start, mid - 1);
    root->right = buildAVLFromArray(arr, mid + 1, end);

    updateHeight(root);

    return root;
}

void Notepad::loadDict(TreeNode* &treeRoot) {
    string filename = "dictionary.txt";

    int wordCount = countLines(filename);
    cout << "Word count: " << wordCount << endl;

    auto* words = new string[wordCount];
    loadArray(filename, words, wordCount);

    mergeSort(words, 0, wordCount - 1);

    treeRoot = buildAVLFromArray(words, 0, wordCount - 1);

    cout << "Tree built successfully. Root word: "
         << (treeRoot ? treeRoot->word : "null") << endl;

    delete[] words;
}

void Notepad::initialise() {
    loadDict(tree.getRoot());

    tree.inOrder();
    cout << endl;
}
