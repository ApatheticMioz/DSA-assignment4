#ifndef ALGORITHMS_H
#define ALGORITHMS_H

using namespace std;
#include <string>

#include "AVL_tree.h"

void merge(string *arr, int left, int mid, int right);

void mergeSort(string *arr, int left, int right);

int max(int a, int b);

bool isPrint(int ch);

string subStr(const string& str, int start, int length = 0);

string substitution(const string& word, AVL_tree &tree);

string omission(const string& word, AVL_tree &tree);

string insertion(const string& word, AVL_tree &tree);

string reversal(const string& word, AVL_tree &tree);

#endif //ALGORITHMS_H
