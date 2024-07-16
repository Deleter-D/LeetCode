/*
    Topic link: https://leetcode.cn/problems/insert-into-a-binary-search-tree/
*/
#include "utils/TreeNode.h"
#include <cassert>

TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    if (val > root->val)
        root->right = insertIntoBST(root->right, val);
    return root;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode *res = insertIntoBST(root, 5);

    assert(res->right->left->val == 5);
    return 0;
}
