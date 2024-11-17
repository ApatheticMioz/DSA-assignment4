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
    auto* root = new TreeNode(arr[mid]);

    root->left = buildAVLFromArray(arr, start, mid - 1);
    root->right = buildAVLFromArray(arr, mid + 1, end);

    updateHeight(root);

    return root;
}

void Notepad::loadDict(TreeNode* &treeRoot) {
    string filename = "dictionary.txt";

    int wordCount = countLines(filename);

    auto* words = new string[wordCount];
    loadArray(filename, words, wordCount);

    mergeSort(words, 0, wordCount - 1);

    treeRoot = buildAVLFromArray(words, 0, wordCount - 1);

    delete[] words;
}

void Notepad::initialiseDict() {
    loadDict(tree.getRoot());
}

void Notepad::display() const {
    list.display();
}

void Notepad::loadFile(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    list.delList();

    char ch;
    while (file.get(ch)) {
        list.insertAtEnd(ch);
    }

    file.close();
}

void Notepad::saveFile() {
    ofstream file("save.txt");

    if (!file) {
        cerr << "Error creating or opening file " << "save.txt" << endl;
    }

    Node* current = list.getHead();
    while (current) {
        file.put(current->letter);
        current = current->next;
    }

    file.close();

    cout << "File saved as save.txt" << endl;
}

void Notepad::undo() {

}

void Notepad::deleteLast() {

}

void Notepad::writeCh(const char ch) {
    list.insertAtEnd(ch);
}





