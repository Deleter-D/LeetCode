/*
    Topic link:
   https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/
#include "utils/TreeNode.h"
#include <cassert>
#include <iostream>
#include <vector>

TreeNode *traversal(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (preorder.size() == 0) {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[0]);

    if (preorder.size() == 1)
        return root;

    int delimiter;
    for (delimiter = 0; delimiter < inorder.size(); delimiter++) {
        if (inorder[delimiter] == root->val)
            break;
    }

    std::vector<int> left_inorder(inorder.begin(), inorder.begin() + delimiter);
    std::vector<int> right_inorder(inorder.begin() + delimiter + 1,
                                   inorder.end());

    std::vector<int> new_preorder(preorder.begin() + 1, preorder.end());
    std::vector<int> left_preorder(new_preorder.begin(),
                                   new_preorder.begin() + left_inorder.size());
    std::vector<int> right_preorder(new_preorder.begin() + left_inorder.size(),
                                    new_preorder.end());

    root->left = traversal(left_preorder, left_inorder);
    root->right = traversal(right_preorder, right_inorder);

    return root;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) {
        return nullptr;
    }
    return traversal(preorder, inorder);
}

int main(int argc, char const *argv[]) {
    std::vector<int> preorder{3, 9, 20, 15, 7};
    std::vector<int> inorder{9, 3, 15, 20, 7};

    TreeNode *res = buildTree(preorder, inorder);

    assert(res->val == 3);
    assert(res->left->val == 9);
    assert(res->right->val == 20);
    assert(res->right->left->val == 15);
    assert(res->right->right->val == 7);

    return 0;
}
