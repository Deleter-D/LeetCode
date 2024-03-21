/*
    Topic link: https://leetcode.cn/problems/minimum-depth-of-binary-tree/
*/
#include "../utils/TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

int minDepth(TreeNode *root) {
    int depth = 0;
    queue<TreeNode *> q;

    if (root == nullptr)
        return depth;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        depth++;
        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left == nullptr && node->right == nullptr)
                return depth;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return depth;
}

int main(int argc, char *argv[]) {
    TreeNode *node5 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(20, node4, node5);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *root = new TreeNode(3, node2, node3);

    cout << minDepth(root) << endl;

    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete root;
    node5 = node4 = node3 = node2 = root = nullptr;
    return 0;
}
