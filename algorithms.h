// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

using namespace std;
#include <string>

#include "AVL_tree.h"

/*
 * The file is created to manage some algorithms that were required to build the
 * console based notepad.
 */

// Helper function as required by a normal merge sort
// Merges arrays in ascending order
void merge(string *arr, int left, int mid, int right);

// Merge sort, sort the array in ascending order
void mergeSort(string *arr, int left, int right);

// Return the maximum value
int max(int a, int b);

// Return if given character is a printable character or not
// i.e a non control character like 'ESC'
bool isPrint(int ch);

// Return a sub string from a string, specified by start and length
string subStr(const string& str, int start, int length = 0);

// The documentation for the spell checking methods is provided in Notepad.h
// Please refer to that header file if you need further explanations
string substitution(const string& word, AVL_tree &tree);

string omission(const string& word, AVL_tree &tree);

string insertion(const string& word, AVL_tree &tree);

string reversal(const string& word, AVL_tree &tree);
// Spell checking algorithms end here


#endif //ALGORITHMS_H
