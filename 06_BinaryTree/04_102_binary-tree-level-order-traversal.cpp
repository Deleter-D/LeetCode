/*
    Topic link: https://leetcode.cn/problems/binary-tree-level-order-traversal/
*/
#include "../utils/TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 递归法
void order(TreeNode *node, vector<vector<int>> &res, int depth) {
    if (node == nullptr)
        return;
    if (res.size() == depth)
        res.push_back(vector<int>());
    res[depth].push_back(node->val);
    order(node->left, res, depth + 1);
    order(node->right, res, depth + 1);
}

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    int depth = 0;
    order(root, res, depth);
    return res;
}

// 迭代法
vector<vector<int>> levelOrder2(TreeNode *root) {
    queue<TreeNode *> q;
    vector<vector<int>> res;

    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty()) {
        // 记录当前队列大小，即当前层的结点数
        int size = q.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();
            vec.push_back(node->val); // 遍历本层结点
            if (node->left)
                q.push(node->left); // 左子结点入队
            if (node->right)
                q.push(node->right); // 右子结点入队
        }
        res.push_back(vec); // 将当前层加入结果集
    }

    return res;
}

int main(int argc, char *argv[]) {
    TreeNode *node5 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(20, node4, node5);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *root = new TreeNode(3, node2, node3);

    // vector<vector<int>> res = levelOrder(root);
    vector<vector<int>> res = levelOrder2(root);
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
