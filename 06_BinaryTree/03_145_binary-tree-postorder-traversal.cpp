/*
    Topic link: https://leetcode.cn/problems/binary-tree-postorder-traversal/
*/
#include "../utils/TreeNode.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 递归法
void postOrder(TreeNode *node, vector<int> &res) {
    if (node != nullptr) {
        postOrder(node->left, res);
        postOrder(node->right, res);
        res.push_back(node->val);
    }
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    postOrder(root, res);
    return res;
}

// 迭代法
vector<int> postorderTraversal2(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> res;

    // 大部分与前序遍历相同
    if (root == nullptr)
        return res;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        res.push_back(node->val); // 中
        // 这里颠倒左右结点入栈顺序
        // 使遍历顺序变为中右左
        if (node->left)
            st.push(node->left); // 左
        if (node->right)
            st.push(node->right); // 右
    }

    // 反转遍历结果，变为左右中
    reverse(res.begin(), res.end());
    return res;
}

// 统一迭代法
vector<int> postorderTraversal3(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> res;

    if (root != nullptr)
        st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        if (node != nullptr) {
            st.pop();

            st.push(node); // 中
            st.push(nullptr);
            if (node->right)
                st.push(node->right); // 右
            if (node->left)
                st.push(node->left); // 左
        } else {
            st.pop();
            node = st.top();
            st.pop();
            res.push_back(node->val);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2, node3, nullptr);
    TreeNode *root = new TreeNode(1, nullptr, node2);

    // vector<int> res = postorderTraversal(root);
    // vector<int> res = postorderTraversal2(root);
    vector<int> res = postorderTraversal3(root);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    delete node3;
    delete node2;
    delete root;
    node3 = nullptr;
    node2 = nullptr;
    root = nullptr;
    return 0;
}
