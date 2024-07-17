/*
    Topic link: https://leetcode.cn/problems/convert-bst-to-greater-tree/
*/
#include "utils/TreeNode.h"
#include <cassert>

TreeNode *pre = nullptr;

TreeNode *convertBST(TreeNode *root) {
    if (root == nullptr)
        return nullptr;

    if (root->right != nullptr)
        root->right = convertBST(root->right);

    if (pre != nullptr)
        root->val += pre->val;
    pre = root;

    if (root->left != nullptr)
        root->left = convertBST(root->left);

    return root;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    TreeNode *res = convertBST(root);

    assert(res->val == 30);
    assert(res->left->val == 36);
    assert(res->right->val == 21);
    assert(res->left->left->val == 36);
    assert(res->left->right->val == 35);
    assert(res->left->right->right->val == 33);
    assert(res->right->left->val == 26);
    assert(res->right->right->val == 15);
    assert(res->right->right->right->val == 8);
    return 0;
}
