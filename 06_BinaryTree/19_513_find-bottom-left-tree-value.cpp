/*
    Topic link: https://leetcode.cn/problems/find-bottom-left-tree-value/
*/
#include "utils/TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;
    int res;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            if (i == 0)
                res = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return res;
}

int main(int argc, char const *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    cout << findBottomLeftValue(root) << endl;

    return 0;
}