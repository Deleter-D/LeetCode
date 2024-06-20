/*
    Topic link: https://leetcode.cn/problems/binary-tree-inorder-traversal/
*/
#include "utils/TreeNode.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 递归法
void inOrder(TreeNode *node, vector<int> &res) {
    if (node != nullptr) {
        inOrder(node->left, res);
        res.push_back(node->val);
        inOrder(node->right, res);
    }
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    inOrder(root, res);
    return res;
}

// 迭代法
vector<int> inorderTraversal2(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> res;

    TreeNode *cur = root;
    while (cur != nullptr || !st.empty()) {
        if (cur != nullptr) {
            // 一直遍历到树的最左下角结点
            st.push(cur);
            cur = cur->left; // 左
        } else {
            // 栈顶元素为待处理的结点
            cur = st.top();
            st.pop();
            res.push_back(cur->val); // 中
            cur = cur->right;        // 右
        }
    }

    return res;
}

// 统一迭代法
vector<int> inorderTraversal3(TreeNode *root) {
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
            st.push(node);            // 中
            st.push(nullptr); // 中间结点访问过但还未处理，加入nullptr作为标记
            if (node->left)
                st.push(node->left); // 左
        } else {      // 遇到nullptr才将下一个结点放入结果集中
            st.pop(); // 弹出空结点
            node = st.top(); // 取出栈中元素
            st.pop();
            res.push_back(node->val); // 加入结果集
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2, node3, nullptr);
    TreeNode *root = new TreeNode(1, nullptr, node2);

    // vector<int> res = inorderTraversal(root);
    // vector<int> res = inorderTraversal2(root);
    vector<int> res = inorderTraversal3(root);
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
