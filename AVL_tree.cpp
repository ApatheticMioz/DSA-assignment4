#include "AVL_tree.h"
#include <iostream>
#include <string>
using namespace std;

Node::Node(const string& word) : word(word), height(0), left(nullptr), right(nullptr) {}

AVL_tree::AVL_tree() : treeRoot(nullptr) {}

void AVL_tree::insert(const string &word) {
    insert(treeRoot, word);
}

bool AVL_tree::search(const string &word) {
    return search(treeRoot, word);
}

Node* AVL_tree::delNode(const string &word) {
    return delNode(treeRoot, word);
}

void AVL_tree::inOrder() {
    inOrder(treeRoot);
}

