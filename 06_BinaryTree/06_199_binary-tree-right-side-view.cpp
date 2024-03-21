/*
    Topic link: https://leetcode.cn/problems/binary-tree-right-side-view/
*/
#include "../utils/TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    queue<TreeNode *> q;

    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            if (i == size - 1)
                res.push_back(node->val);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(3, nullptr, node5);
    TreeNode *node3 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(2, nullptr, node3);
    TreeNode *root = new TreeNode(1, node2, node4);

    vector<int> res = rightSideView(root);
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
