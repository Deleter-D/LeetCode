/*
    Topic link:
   https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
*/
#include "../utils/TreeNode.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> q;

    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            vec.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        res.push_back(vec);
    }
    reverse(res.begin(), res.end());

    return res;
}

int main(int argc, char *argv[]) {
    TreeNode *node5 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(20, node4, node5);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *root = new TreeNode(3, node2, node3);

    vector<vector<int>> res = levelOrderBottom(root);
    for (vector<int> vec : res) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete root;
    node5 = node4 = node3 = node2 = root = nullptr;
    return 0;
}
