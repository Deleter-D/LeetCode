/*
    Topic link: https://leetcode.cn/problems/validate-binary-search-tree/
*/
#include "utils/TreeNode.h"
#include <cassert>

TreeNode *pre = nullptr;
bool isValidBST(TreeNode *root) {
    if (root == nullptr)
        return true;

    bool left = isValidBST(root->left);

    if (pre != nullptr && pre->val >= root->val)
        return false;

    pre = root;

    bool right = isValidBST(root->right);
    return left && right;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    assert(isValidBST(root) == true);
    return 0;
}
