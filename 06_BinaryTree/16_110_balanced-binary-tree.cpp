/*
    Topic link: https://leetcode.cn/problems/balanced-binary-tree/
*/
#include "utils/TreeNode.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int getHeight(TreeNode *node) {
    if (node == nullptr)
        return 0;

    // 左右子树任何一个不是平衡二叉树就直接返回-1
    int leftHeight = getHeight(node->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = getHeight(node->right);
    if (rightHeight == -1)
        return -1;

    // 左右子树高度差大于1则返回-1
    // 不大于1则返回较高子树高度+1
    return abs(leftHeight - rightHeight) > 1 ? -1
                                             : 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode *root) { return getHeight(root) == -1 ? false : true; }

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << getHeight(root) << endl;

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}
