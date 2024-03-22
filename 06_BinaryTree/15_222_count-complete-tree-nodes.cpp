/*
    Topic link: https://leetcode.cn/problems/count-complete-tree-nodes/
*/
#include "../utils/TreeNode.h"
#include <iostream>
using namespace std;

int countNodes(TreeNode *root) {
    if (root == nullptr)
        return 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftDepth = 0, rightDepth = 0;
    while (left != nullptr) { // 求左子树深度
        left = left->left;
        leftDepth++;
    }
    while (right != nullptr) { // 求右子树深度
        right = right->right;
        rightDepth++;
    }
    if (leftDepth == rightDepth) // 满二叉树的情况
        return (2 << leftDepth) - 1;
    // 叶子结点未满的情况
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << countNodes(root) << endl;

    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}
