/*
    Topic link: https://leetcode.cn/problems/search-in-a-binary-search-tree/
*/
#include "utils/TreeNode.h"
#include <cassert>

TreeNode *searchBST(TreeNode *root, int val) {
    if (root != nullptr) {
        if (root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        else if (root->val < val)
            return searchBST(root->right, val);
    }
    return nullptr;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode *res = searchBST(root, 5);

    assert(res == nullptr);
    return 0;
}
