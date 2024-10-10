/*
    Topic link: https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
*/
#include "utils/ListNode.h"
#include "utils/TreeNode.h"
#include <cassert>
#include <iostream>
#include <stack>

void flatten(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    std::stack<TreeNode *> st;
    st.push(root);
    TreeNode *prev = nullptr;
    while (!st.empty()) {
        TreeNode *cur = st.top();
        st.pop();

        if (prev != nullptr) {
            prev->left = nullptr;
            prev->right = cur;
        }

        TreeNode *left = cur->left;
        TreeNode *right = cur->right;
        if (right != nullptr) {
            st.push(right);
        }
        if (left != nullptr) {
            st.push(left);
        }
        prev = cur;
    }
}

int main(int argc, char const *argv[]) {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);

    flatten(root);

    assert(root->val == 2);
    assert(root->right->val == 1);
    assert(root->right->right->val == 4);
    assert(root->right->right->right->val == 3);
    return 0;
}
