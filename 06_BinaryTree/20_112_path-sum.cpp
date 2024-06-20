/*
    Topic link: https://leetcode.cn/problems/path-sum/
*/
#include "utils/TreeNode.h"
#include <iostream>
#include <stack>
using namespace std;

void preOrder(TreeNode *node, int &sum, int targetSum, bool &res) {
    sum += node->val;

    if (node->left == nullptr && node->right == nullptr && sum == targetSum) {
        res = true;
        return;
    }

    if (node->left != nullptr) {
        preOrder(node->left, sum, targetSum, res);
        sum -= node->left->val;
    }
    if (node->right != nullptr) {
        preOrder(node->right, sum, targetSum, res);
        sum -= node->right->val;
    }
}

bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr)
        return false;

    bool res = false;
    int sum = 0;
    preOrder(root, sum, targetSum, res);

    return res;
}

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    cout << hasPathSum(root, 22) << endl;

    return 0;
}
