/*
    Topic link: https://leetcode.cn/problems/delete-node-in-a-bst/
*/
#include "utils/TreeNode.h"
#include <cassert>

TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
        return root;

    if (key == root->val) {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            TreeNode *node = root->right;
            delete root;
            return node;
        } else if (root->right == nullptr) {
            TreeNode *node = root->left;
            delete root;
            return node;
        } else {
            TreeNode *cur = root->right;
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            cur->left = root->left;
            TreeNode *tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
    }

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    if (key > root->val)
        root->right = deleteNode(root->right, key);

    return root;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    TreeNode *res = deleteNode(root, 3);

    assert(res->val == 5);
    assert(res->left->val == 4);
    assert(res->right->val == 6);
    assert(res->left->left->val == 2);
    assert(res->right->right->val == 7);
    return 0;
}
