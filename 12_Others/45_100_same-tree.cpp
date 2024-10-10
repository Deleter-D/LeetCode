/*
    Topic link: https://leetcode.cn/problems/same-tree/
*/
#include "utils/TreeNode.h"
#include <iostream>

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
        return true;
    } else if ((p == nullptr && q != nullptr) ||
               (p != nullptr && q == nullptr)) {
        return false;
    }

    if (p->val == q->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } else {
        return false;
    }
}

int main(int argc, char const *argv[]) {
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);

    TreeNode *q = new TreeNode(1);
    q->right = new TreeNode(2);

    bool res = isSameTree(p, q);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
