/*
    Topic link:
    https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
*/
#include "../utils/TreeNode.h"
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> largestValues(TreeNode *root) {
    vector<int> res;
    queue<TreeNode *> q;

    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        int max = INT_MIN;
        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            if (node->val > max)
                max = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        res.push_back(max);
    }

    return res;
}

int main(int argc, char *argv[]) {
    TreeNode *node6 = new TreeNode(9);
    TreeNode *node5 = new TreeNode(2, nullptr, node6);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(3, node3, node4);
    TreeNode *root = new TreeNode(1, node2, node5);

    vector<int> res = largestValues(root);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    delete node6;
    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete root;
    node6 = node5 = node4 = node3 = node2 = root = nullptr;
    return 0;
}
