/*
    Topic link:
    https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/
#include "utils/TreeNode.h"
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {
    if (postorder.size() == 0)
        return nullptr;

    // root node
    int root_value = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode(root_value);

    // leave node
    if (postorder.size() == 1)
        return root;

    // find the cutting point
    int delimiter;
    for (delimiter = 0; delimiter < inorder.size(); delimiter++) {
        if (inorder[delimiter] == root_value)
            break;
    }

    // left inorder: [begin, delimiter)
    vector<int> left_inorder(inorder.begin(), inorder.begin() + delimiter);
    // right inorder: [delimiter + 1, end)
    vector<int> right_inorder(inorder.begin() + delimiter + 1, inorder.end());

    // remove the root value
    postorder.resize(postorder.size() - 1);
    // left postorder: [0, left_inorder.size())
    vector<int> left_postorder(postorder.begin(),
                               postorder.begin() + left_inorder.size());
    // right postorder: [left_inorder.size(), end)
    vector<int> right_postorder(postorder.begin() + left_inorder.size(),
                                postorder.end());

    root->left = traversal(left_inorder, left_postorder);
    root->right = traversal(right_inorder, right_postorder);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0 || postorder.size() == 0)
        return nullptr;
    return traversal(inorder, postorder);
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> inorder{9, 3, 15, 20, 7};
    vector<int> postorder{9, 15, 7, 20, 3};
    TreeNode *res = buildTree(inorder, postorder);

    assert(res->val == root->val);
    assert(res->left->val == root->left->val);
    assert(res->right->val == root->right->val);
    assert(res->right->left->val == root->right->left->val);
    assert(res->right->right->val == root->right->right->val);
    return 0;
}
