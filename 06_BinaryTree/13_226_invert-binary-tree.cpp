/*
    Topic link: https://leetcode.cn/problems/invert-binary-tree/
*/
#include "../utils/TreeNode.h"
#include <stack>
#include <utility>
using namespace std;

TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
        return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

TreeNode *invertTree2(TreeNode *root) {
    if (root == nullptr)
        return root;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        swap(node->left, node->right);
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }

    return root;
}

int main(int argc, char *argv[]) {
    TreeNode *node7 = new TreeNode(9);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(7, node6, node7);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2, node3, node4);
    TreeNode *root = new TreeNode(4, node2, node5);

    delete node7;
    delete node6;
    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete root;
    node7 = node6 = node5 = node4 = node3 = node2 = root = nullptr;
    return 0;
}
