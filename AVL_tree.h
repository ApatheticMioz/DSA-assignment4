#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>
using namespace std;

class Node {
public:
    string word;
    int height;
    Node* left;
    Node* right;

    explicit Node(const string &word);
};

class AVL_tree {
    Node* treeRoot;

    int getHeight(Node* node);

    int getBalance(Node* node);

    Node* rightRotate(Node* node);

    Node* leftRotate(Node* node);

    Node* insertionRotations(Node* node, const string& key);

    Node* insert(Node* root, const string& key);

    Node* getSuccessor(Node* current);

    Node* deletionRotations(Node* node);

    Node* delNode(Node* root, const string& key);

    bool search(Node* root, const string& key);

    void inOrder(Node* root);

public:
    AVL_tree();

    void insert(const string &word);

    bool search(const string &word);

    Node* delNode(const string &word);

    void inOrder();
};

#endif //AVL_TREE_H
