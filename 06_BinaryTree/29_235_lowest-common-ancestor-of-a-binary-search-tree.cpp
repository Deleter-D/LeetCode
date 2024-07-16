/*
    Topic link:
   https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/
#include "utils/TreeNode.h"
#include <algorithm>
#include <cassert>
using namespace std;

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q)
        return root;

    TreeNode *small =
        min(p, q, [](TreeNode *a, TreeNode *b) { return a->val < b->val; });
    TreeNode *large = small == p ? q : p;

    if (small->val < root->val && large->val > root->val)
        return root;

    if (large->val < root->val && root->left != nullptr)
        return lowestCommonAncestor(root->left, p, q);
    else if (small->val > root->val && root->right != nullptr)
        return lowestCommonAncestor(root->right, p, q);
    else
        return nullptr;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode *res = lowestCommonAncestor(root, root->left, root->left->right);

    assert(res == root->left);
    return 0;
}
