/*
    Topic link: https://leetcode.cn/problems/binary-tree-preorder-traversal/
*/
#include "../utils/TreeNode.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 递归法
void preOrder(TreeNode *node, vector<int> &res) {
    if (node != nullptr) {
        res.push_back(node->val);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }
}

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    preOrder(root, res);
    return res;
}

// 迭代法
vector<int> preorderTraversal2(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> res;

    if (root == nullptr)
        return res;
    st.push(root);
    while (!st.empty()) {
        // 栈顶元素即为中间结点
        TreeNode *node = st.top();
        st.pop();
        res.push_back(node->val); // 中
        // 要使出栈顺序是中左右，则必须先将右孩子入栈
        if (node->right)
            st.push(node->right); // 右
        if (node->left)
            st.push(node->left); // 左
    }

    return res;
}

// 统一迭代法
vector<int> preorderTraversal3(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> res;

    if (root != nullptr)
        st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        if (node != nullptr) {
            st.pop(); // 弹出当前结点避免重复操作

            if (node->right)
                st.push(node->right); // 右
            if (node->left)
                st.push(node->left); // 左
            st.push(node);           // 中
            st.push(nullptr);
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

    // vector<int> res = preorderTraversal(root);
    // vector<int> res = preorderTraversal2(root);
    vector<int> res = preorderTraversal3(root);
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
