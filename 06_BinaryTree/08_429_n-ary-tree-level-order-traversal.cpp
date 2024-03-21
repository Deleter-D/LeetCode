/*
    Topic link: https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
*/
#include "../utils/NaryTreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> levelOrder(NaryTreeNode *root) {
    vector<vector<int>> res;
    queue<NaryTreeNode *> q;

    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            NaryTreeNode *node = q.front();
            q.pop();
            vec.push_back(node->val);
            for (NaryTreeNode *child : node->children) {
                q.push(child);
            }
        }
        res.push_back(vec);
    }

    return res;
}

int main(int argc, char *argv[]) {
    NaryTreeNode *node6 = new NaryTreeNode(6);
    NaryTreeNode *node5 = new NaryTreeNode(5);
    NaryTreeNode *node4 = new NaryTreeNode(4);
    NaryTreeNode *node3 = new NaryTreeNode(2);
    NaryTreeNode *node2 = new NaryTreeNode(3, {node5, node6});
    NaryTreeNode *root = new NaryTreeNode(1, {node2, node3, node4});

    vector<vector<int>> res = levelOrder(root);

    for (vector<int> vec : res) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    delete node6;
    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete root;
    node6 = node5 = node4 = node3 = node2 = root = nullptr;

    return 0;
}
