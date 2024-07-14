/*
    Topic link:
   https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
*/
#include "utils/TreeNode.h"
#include <vector>
using namespace std;

void traversal(TreeNode *root, const int target, vector<int> &path) {
    if (root == nullptr)
        return;

    path.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr)
        return;

    if (root->left != nullptr) {
        traversal(root->left, target, path);
        path.pop_back();
    }
    if (root->right != nullptr) {
        traversal(root->right, target, path);
        path.pop_back();
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {}
