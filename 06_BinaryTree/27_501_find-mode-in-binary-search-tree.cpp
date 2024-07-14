/*
    Topic link: https://leetcode.cn/problems/find-mode-in-binary-search-tree/
*/
#include "utils/TreeNode.h"
#include <iostream>
#include <vector>
using namespace std;

int max_count = 0;
int count = 0;
TreeNode *pre_node = nullptr;

void traversal(TreeNode *root, vector<int> &res) {
    if (root == nullptr)
        return;

    traversal(root->left, res);

    if (pre_node == nullptr) {
        // first node
        count = 1;
    } else if (pre_node->val == root->val) {
        // same value with previous node
        count++;
    } else {
        // don't same
        count = 1;
    }
    pre_node = root;

    if (count == max_count) {
        res.push_back(root->val);
    }

    if (count > max_count) {
        max_count = count;
        res.clear(); // most important step
        res.push_back(root->val);
    }

    traversal(root->right, res);
}

vector<int> findMode(TreeNode *root) {
    vector<int> res;
    traversal(root, res);
    return res;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    vector<int> res = findMode(root);

    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
