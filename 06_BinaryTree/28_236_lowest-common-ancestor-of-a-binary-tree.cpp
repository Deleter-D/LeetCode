/*
    Topic link:
   https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
*/
#include "utils/TreeNode.h"
#include <cassert>
#include <pthread.h>
#include <vector>
using namespace std;

void traversal(TreeNode *root, TreeNode *target, vector<TreeNode *> &record,
               vector<TreeNode *> &path) {
    if (root == nullptr)
        return;

    record.push_back(root);

    if (root->val == target->val) {
        for (TreeNode *node : record)
            path.push_back(node);
        return;
    } else {
        if (root->left != nullptr) {
            traversal(root->left, target, record, path);
            record.pop_back();
        }
        if (root->right != nullptr) {
            traversal(root->right, target, record, path);
            record.pop_back();
        }
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> record;

    vector<TreeNode *> p_path;
    traversal(root, p, record, p_path);

    record.clear();
    vector<TreeNode *> q_path;
    traversal(root, q, record, q_path);

    int size = min(p_path.size(), q_path.size());
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (p_path[i]->val == q_path[i]->val)
            index = i;
        else
            break;
    }

    return p_path[index];
}

TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == p || root == q || root == nullptr)
        return root;

    TreeNode *left = lowestCommonAncestor2(root->left, p, q);
    TreeNode *right = lowestCommonAncestor2(root->right, p, q);
    if (left != nullptr && right != nullptr)
        return root;
    if (left == nullptr && right != nullptr)
        return right;
    else if (left != nullptr && right == nullptr)
        return left;
    else
        return nullptr;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *res1 =
        lowestCommonAncestor(root, root->left, root->left->right->right);

    TreeNode *res2 =
        lowestCommonAncestor2(root, root->left, root->left->right->right);

    assert(res1 == root->left);
    assert(res2 == root->left);
    return 0;
}
