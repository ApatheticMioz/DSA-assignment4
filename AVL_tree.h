#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>

using namespace std;

class TreeNode {
public:
    string word;
    int height;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(const string &word);
};

void updateHeight(TreeNode* node);

int getHeight(TreeNode* node);

class AVL_tree {
    TreeNode* treeRoot;

    void deleteTree(TreeNode* root);

    int getBalance(TreeNode* node) const;

    TreeNode* rightRotate(TreeNode* node);

    TreeNode* leftRotate(TreeNode* node);

    TreeNode* insertionRotations(TreeNode* node, const string& word);

    TreeNode* insert(TreeNode* root, const string& word);

    TreeNode* getSuccessor(TreeNode* current);

    TreeNode* deletionRotations(TreeNode* node);

    TreeNode* delNode(TreeNode* root, const string& word);

    bool search(TreeNode* root, const string& word);

    void inOrder(TreeNode* root);

public:
    AVL_tree();

    ~AVL_tree();

    TreeNode*& getRoot();

    void insert(const string &word);

    bool search(const string &word);

    void delNode(const string &word);

    void inOrder();
};

#endif //AVL_TREE_H
