/*
    Topic link: https://leetcode.cn/problems/merge-two-binary-trees/
*/
#include "utils/TreeNode.h"
#include <cassert>
#include <queue>
using namespace std;

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

int main(int argc, char *argv[]) {
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    TreeNode *res = mergeTrees(root1, root2);

    assert(res->val == root->val);
    assert(res->left->val == root->left->val);
    assert(res->right->val == root->right->val);
    assert(res->left->left->val == root->left->left->val);
    assert(res->left->right->val == root->left->right->val);
    assert(res->right->right->val == root->right->right->val);

    return 0;
}
