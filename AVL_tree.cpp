#include "AVL_tree.h"
#include "algorithms.h"

#include <iostream>
#include <string>
using namespace std;

TreeNode::TreeNode(const string& word) : word(word), height(1), left(nullptr), right(nullptr) {}

AVL_tree::AVL_tree() : treeRoot(nullptr) {}

void AVL_tree::deleteTree(TreeNode *root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

AVL_tree::~AVL_tree() {
    deleteTree(treeRoot);
}

TreeNode*& AVL_tree::getRoot() {
    return treeRoot;
}

int getHeight(TreeNode* node) {
    if (node == nullptr)
        return 0;

    return node->height;
}

void updateHeight(TreeNode *node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

int AVL_tree::getBalance(TreeNode* node) const {
    if (node == nullptr)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* AVL_tree::rightRotate(TreeNode* node) {
    TreeNode* newNode = node->left;
    node->left = newNode->right;
    newNode->right = node;

    updateHeight(node);
    updateHeight(newNode);

    return newNode;
}

TreeNode* AVL_tree::leftRotate(TreeNode* node) {
    TreeNode* newNode = node->right;
    node->right = newNode->left;
    newNode->left = node;

    updateHeight(node);
    updateHeight(newNode);

    return newNode;
}

TreeNode* AVL_tree::insertionRotations(TreeNode* node, const string& word) {
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

TreeNode* AVL_tree::insert(TreeNode* root, const string& word) {
    if (root == nullptr)
        return new TreeNode(word);

    if (word < root->word)
        root->left = insert(root->left, word);
    else if (word > root->word)
        root->right = insert(root->right, word);
    else
        return root;

    updateHeight(root);

    return insertionRotations(root, word);
}

void AVL_tree::insert(const string &word) {
    treeRoot = insert(treeRoot, word);
}

bool AVL_tree::search(TreeNode* root, const string &word) {
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

TreeNode *AVL_tree::getSuccessor(TreeNode *current) {
    current = current->right;
    while (current != nullptr && current->left != nullptr)
        current = current->left;

    return current;
}

TreeNode *AVL_tree::deletionRotations(TreeNode *node) {
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

TreeNode* AVL_tree::delNode(TreeNode* root, const string& word) {
    if (root == nullptr)
        return root;

    if (word < root->word)
        root->left = delNode(root->left, word);
    else if (word > root->word)
        root->right = delNode(root->right, word);
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            root = temp;
        } else {
            TreeNode* successor = getSuccessor(root);
            root->word = successor->word;
            root->right = delNode(root->right, successor->word);
        }
    }

    if (root == nullptr)
        return root;

    updateHeight(root);

    return deletionRotations(root);
}

void AVL_tree::delNode(const string &word) {
    treeRoot = delNode(treeRoot, word);
}

void AVL_tree::inOrder(TreeNode* root) {
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->word << " ";
    inOrder(root->right);
}

void AVL_tree::inOrder() {
    inOrder(treeRoot);
}
