// Muhammad Abdullah Ali
// i23-2523
// Section A
// Department of Data Science
// Data Structures
// Assignment #4

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>

using namespace std;

/*
 * The AVL tree was used to load the dictionary provided.
 *
 * An AVL tree was a good choice as it allows for quick searching
 */

class TreeNode {
public:
    string word;
    int height;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(const string &word);
};

// Function to update the height of a node
void updateHeight(TreeNode* node);

// Function to retrieve the height of a node
int getHeight(TreeNode* node);

class AVL_tree {
    TreeNode* treeRoot;

    // Function to free the memory taken by the tree
    void deleteTree(TreeNode* root);

    // Function to retrieve the balance factor of a node
    int getBalance(TreeNode* node) const;

    // Function to apply right rotation on a node
    TreeNode* rightRotate(TreeNode* node);

    // Function to apply left rotation on a node
    TreeNode* leftRotate(TreeNode* node);

    // After inserting an element, apply the necessary rotations on the node
    TreeNode* insertionRotations(TreeNode* node, const string& word);

    // Insert an element using BST rules
    TreeNode* insert(TreeNode* root, const string& word);

    // Get the node to replace the node to be deleted with
    // Smallest value in right subtree
    TreeNode* getSuccessor(TreeNode* current);

    // After deletion of a node, apply the necessary rotations on the node
    TreeNode* deletionRotations(TreeNode* node);

    // Delete a node using BST rules
    TreeNode* delNode(TreeNode* root, const string& word);

    // Search for a node in the AVL tree
    bool search(TreeNode* root, const string& word);

    // Print the tree in inOrder fashion
    void inOrder(TreeNode* root);

public:
    // Constructor
    AVL_tree();

    // Destructor
    ~AVL_tree();

    // Get the root node of the tree
    TreeNode*& getRoot();

    // Insert a word into the tree
    void insert(const string &word);

    // Search for a word in the tree
    bool search(const string &word);

    // Delete a node containing the word in the tree
    void delNode(const string &word);

    // Print the tree in inOrder fashion
    void inOrder();
};

#endif //AVL_TREE_H
