/*
    Topic link: https://leetcode.cn/problems/house-robber-iii/
*/
#include "utils/TreeNode.h"
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> robTree(TreeNode *node) {
    if (node == nullptr)
        return {0, 0};

    std::vector<int> left = robTree(node->left);
    std::vector<int> right = robTree(node->right);

    int notSteal = std::max(left[0], left[1]) + std::max(right[0], right[1]);
    int steal = node->val + left[0] + right[0];

    return {notSteal, steal};
}

int rob(TreeNode *root) {
    std::vector<int> res = robTree(root);
    return std::max(res[0], res[1]);
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    int res = rob(root);

    std::cout << res << std::endl;
    return 0;
}
