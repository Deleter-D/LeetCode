/*
    Topic link: https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
*/
#include "utils/TreeNode.h"
#include <cassert>
#include <climits>
#include <cstdlib>

TreeNode *pre_node = nullptr;
int min_diff = INT_MAX;

void traversal(TreeNode *root, int &min_diff) {
    if (root == nullptr)
        return;

    traversal(root->left, min_diff);

    if (pre_node != nullptr) {
        int tmp = abs(root->val - pre_node->val);
        min_diff = tmp < min_diff ? tmp : min_diff;
    }
    pre_node = root;

    traversal(root->right, min_diff);
}

int getMinimumDifference(TreeNode *root) {
    traversal(root, min_diff);
    return min_diff;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int res = getMinimumDifference(root);

    assert(res == 1);
    return 0;
}
