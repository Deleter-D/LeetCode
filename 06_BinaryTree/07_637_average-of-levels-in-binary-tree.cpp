/*
    Topic link: https://leetcode.cn/problems/average-of-levels-in-binary-tree/
*/
#include "utils/TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<double> averageOfLevels(TreeNode *root) {
    vector<double> res;
    queue<TreeNode *> q;

    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            sum += node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        res.push_back(sum / size);
    }

    return res;
}

int main(int argc, char *argv[]) {
    TreeNode *node5 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(20, node4, node5);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *root = new TreeNode(3, node2, node3);

    vector<double> res = averageOfLevels(root);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete root;
    node5 = node4 = node3 = node2 = root = nullptr;
    return 0;
}
