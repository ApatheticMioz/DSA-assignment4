// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#include <string>
#include <iostream>

#include "algorithms.h"

using namespace std;

// The documentation is provided in the header file "algorithms.h"
// Comments/documentation is added in this source file where necessary

void merge(string *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    auto* leftArr = new string[n1];
    auto* rightArr = new string[n2];

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(string *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

bool isPrint(int ch) {
    return ch >= 32 && ch <= 127;
}

string substitution(const string& word, AVL_tree& tree) {
    string modifiedWord = word;

    for (int i = 0; i < word.length(); i++) {
        char originalChar = word[i];

        char start = isupper(originalChar) ? 'A' : 'a';
        char end = isupper(originalChar) ? 'Z' : 'z';

        for (char c = start; c <= end; c++) {
            modifiedWord[i] = c; // Replace the character
            //cout << "Trying substitution: " << modifiedWord << endl; // Debug line
            if (tree.search(modifiedWord)) { // Check if the modified word exists
                return modifiedWord;
            }
        }

        modifiedWord[i] = originalChar; // Restore the original character
    }

    return "Not found";
}

string subStr(const string& str, int start, int length) {
    string result;

    if (start >= str.length()) return ""; // If start is out of bounds, return an empty string

    if (length == 0 || start + length > str.length()) {
        length = str.length() - start; // Adjust length to go to the end of the string
    }

    for (int i = start; i < start + length; i++) {
        result += str[i];
    }

    return result;
}


string omission(const string& word, AVL_tree& tree) {
    for (int i = 0; i < word.length(); i++) {
        // Omit the i-th character
        string modifiedWord = word.substr(0, i) + word.substr(i + 1);

        if (tree.search(modifiedWord)) {
            return modifiedWord;
        }
    }

    return "Not found";
}

string insertion(const string& word, AVL_tree& tree) {
    for (int i = 0; i <= word.length(); i++) {
        char start = isupper(word[0]) ? 'A' : 'a';
        char end = isupper(word[0]) ? 'Z' : 'z';

        for (char c = start; c <= end; c++) {
            // Insert character 'c' at position i
            string modifiedWord = word.substr(0, i) + c + word.substr(i);

            if (tree.search(modifiedWord)) {
                return modifiedWord;
            }
        }
    }

    return "Not found";
}

string reversal(const string& word, AVL_tree& tree) {
    if (word.length() < 2) return "Not found"; // Nothing to reverse if the word has less than 2 characters

    string modifiedWord = word;

    for (int i = 0; i < word.length() - 1; i++) {
        // Swap adjacent characters
        swap(modifiedWord[i], modifiedWord[i + 1]);

        if (tree.search(modifiedWord)) {
            return modifiedWord;
        }

        // Swap back to restore the original word
        swap(modifiedWord[i], modifiedWord[i + 1]);
    }

    return "Not found";
}
