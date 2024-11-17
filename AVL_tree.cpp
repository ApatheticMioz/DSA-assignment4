#include "AVL_tree.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

Node::Node(const string& word) : word(word), height(1), left(nullptr), right(nullptr) {}

AVL_tree::AVL_tree() : treeRoot(nullptr) {}

int AVL_tree::getHeight(Node* node) const {
    if (node == nullptr)
        return 0;

    return node->height;
}

int AVL_tree::getBalance(Node* node) const {
    if (node == nullptr)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

Node* AVL_tree::rightRotate(Node* node) {
    Node* newNode = node->left;
    node->left = newNode->right;
    newNode->right = node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right)) + 1;
    newNode->height = 1 + max(getHeight(newNode->left), getHeight(newNode->right)) + 1;

    return newNode;
}

Node* AVL_tree::leftRotate(Node* node) {
    Node* newNode = node->right;
    node->right = newNode->left;
    newNode->left = node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right)) + 1;
    newNode->height = 1 + max(getHeight(newNode->left), getHeight(newNode->right)) + 1;
}

Node* AVL_tree::insertionRotations(Node* node, const string& word) {
    const int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && word < node->left->word)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && word > node->right->word)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && word > node->left->word) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && word < node->right->word) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* AVL_tree::insert(Node* root, const string& word) {
    if (root == nullptr)
        return new Node(word);

    if (word < root->word)
        root->left = insert(root->left, word);
    else if (word > root->word)
        root->right = insert(root->right, word);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    return insertionRotations(root, word);
}

void AVL_tree::insert(const string &word) {
    treeRoot = insert(treeRoot, word);
}

bool AVL_tree::search(Node* root, const string &word) {
    if (root == nullptr) {
        return false;
    }

    if (root->word == word) {
        return true;
    }

    if (word < root->word) {
        return search(root->left, word);
    }

    return search(root->right, word);
}

bool AVL_tree::search(const string &word) {
    return search(treeRoot, word);
}

Node *AVL_tree::getSuccessor(Node *current) {
    current = current->right;
    while (current != nullptr && current->left != nullptr)
        current = current->left;

    return current;
}

Node *AVL_tree::deletionRotations(Node *node) {
    const int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* AVL_tree::delNode(Node* root, const string& word) {
    if (root == nullptr)
        return root;

    if (word < root->word)
        root->left = delNode(root->left, word);
    else if (word > root->word)
        root->right = delNode(root->right, word);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            root = temp;
        } else {
            Node* successor = getSuccessor(root);
            root->word = successor->word;
            root->right = delNode(root->right, successor->word);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    return deletionRotations(root);
}

void AVL_tree::delNode(const string &word) {
    treeRoot = delNode(treeRoot, word);
}

void AVL_tree::inOrder(Node* root) {
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->word << " ";
    inOrder(root->right);
}

void AVL_tree::inOrder() {
    inOrder(treeRoot);
}
