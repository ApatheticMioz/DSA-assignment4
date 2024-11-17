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

    void deleteTree(Node* root);

    int getHeight(Node* node) const;

    int getBalance(Node* node) const;

    Node* rightRotate(Node* node);

    Node* leftRotate(Node* node);

    Node* insertionRotations(Node* node, const string& word);

    Node* insert(Node* root, const string& word);

    Node* getSuccessor(Node* current);

    Node* deletionRotations(Node* node);

    Node* delNode(Node* root, const string& word);

    bool search(Node* root, const string& word);

    void inOrder(Node* root);

public:
    AVL_tree();

    ~AVL_tree();

    void insert(const string &word);

    bool search(const string &word);

    void delNode(const string &word);

    void inOrder();
};

#endif //AVL_TREE_H
