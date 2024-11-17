#include "Notepad.h"
#include "algorithms.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>

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

    notepadHistory.push(listToString());
    wordHistory.push(queueToString());

    list.delList();
    word.clear();

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
    if (!notepadHistory.isEmpty() && !wordHistory.isEmpty()) {
        auto lastNotepadState = notepadHistory.peek();
        auto lastWordHistory = wordHistory.peek();

        notepadHistory.pop();
        wordHistory.pop();

        list.delList();

        for (char ch : lastNotepadState) {
            list.insertAtEnd(ch);
        }

        stringToQueue(lastWordHistory);
    }
}

void Notepad::deleteLast() {
    if (!list.isEmpty()) {
        notepadHistory.push(listToString());
        wordHistory.push(queueToString());

        list.deleteFromEnd();

        if (word.isEmpty()) {
            Node* lastWordStart = nullptr;
            Node* current = list.getHead();
            Node* prevMeaningful = nullptr;
            bool inWord = false;

            while (current) {
                if (current->letter != ' ' && current->letter != '\n') {
                    if (!inWord) {
                        lastWordStart = current;
                        inWord = true;
                    }
                    prevMeaningful = current;

                } else {
                    inWord = false;
                }

                current = current->next;
            }

            if (!prevMeaningful) {
                word.clear();
                return;
            }

            std::string newLastWord;
            current = lastWordStart;

            while (current && current != prevMeaningful->next) {
                newLastWord += current->letter;
                current = current->next;
            }

            word.clear();
            for (char ch : newLastWord) {
                word.enqueue(ch);
            }
        } else {
            word.dequeue();
        }
    }
}

void Notepad::spellCheck() {
    string wordStr;


    while (!word.isEmpty()) {
        wordStr += word.getFront();
        word.dequeue();
    }

    // cout << "\nWord: " << wordStr << endl;
    // getch();
    //
    // for (auto& ch : wordStr) {
    //     list.deleteFromEnd();
    // }
    //
    // string newStr;
    //
    // for (auto& ch : newStr) {
    //     list.insertAtEnd(ch);
    // }
}

string Notepad::listToString() {
    string result;
    Node* current = list.getHead();

    while (current) {
        result += current->letter;
        current = current->next;
    }

    return result;
}

string Notepad::queueToString() {
    string result;
    Queue tempQueue(word);

    while (!tempQueue.isEmpty()) {
        result += tempQueue.getFront();
        tempQueue.dequeue();
    }

    return result;
}

void Notepad::stringToQueue(const string& str) {
    word.clear();

    for (char ch : str) {
        word.enqueue(ch);
    }
}

void Notepad::writeCh(const char ch) {
    if (isPrint(ch) || ch == '\n') {
        cout << listToString() << endl;
        notepadHistory.push(listToString());
        wordHistory.push(queueToString());
        list.insertAtEnd(ch);
        word.enqueue(ch);
        if (ch == ' ' || ch == '\n') {
            spellCheck();
        }
    }
}





