/*
    Topic link: https://leetcode.cn/problems/sum-of-left-leaves/
*/
#include "../utils/TreeNode.h"
#include <iostream>
#include <vector>
using namespace std;

void preOrder(TreeNode *node, vector<int> &left_leaves) {
    if (node->left != nullptr && node->left->left == nullptr &&
        node->left->right == nullptr)
        left_leaves.push_back(node->left->val);
    if (node->left)
        preOrder(node->left, left_leaves);
    if (node->right)
        preOrder(node->right, left_leaves);
}

int sumOfLeftLeaves(TreeNode *root) {
    vector<int> left_leaves;
    preOrder(root, left_leaves);

    int res = 0;
    for (auto i : left_leaves)
        res += i;

    return res;
}

int main(int argc, char const *argv[]) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sumOfLeftLeaves(root) << endl;

    return 0;
}
