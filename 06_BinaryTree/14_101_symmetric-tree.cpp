/*
    Topic link: https://leetcode.cn/problems/symmetric-tree/
*/
#include "utils/TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

bool compare(TreeNode *left, TreeNode *right) {
    // 首先排除存在空结点的情况
    if (left == nullptr && right != nullptr) // 左空右不空
        return false;
    else if (left != nullptr && right == nullptr) // 左不空右空
        return false;
    else if (left == nullptr && right == nullptr) // 左右都空
        return true;
    // 再排除数值不同的情况
    else if (left->val != right->val) // 左右都不空，但值不相等
        return false;

    // 此时剩下的就是左右结点都不空，且数值相同的情况
    bool outside = compare(left->left, right->right); // 左子树：左、右子树：右
    bool inside = compare(left->right, right->left); // 左子树：右、右子树：左
    return outside && inside; // 左子树：中、右子树：中
}

bool isSymmetric(TreeNode *root) { return compare(root->left, root->right); }

bool isSymmetric2(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root->left);  // 左子树头结点入队
    q.push(root->right); // 右子树头结点入队

    while (!q.empty()) {
        TreeNode *leftNode = q.front();
        q.pop();
        TreeNode *rightNode = q.front();
        q.pop();
        // 左右子树都空
        if (leftNode == nullptr && rightNode == nullptr)
            continue;

        // 左右子树有一个不空，或都不为空但值不相等
        if (leftNode == nullptr || rightNode == nullptr ||
            leftNode->val != rightNode->val)
            return false;

        q.push(leftNode->left);   // 左结点的左孩子
        q.push(rightNode->right); // 右结点的右孩子
        q.push(leftNode->right);  // 左结点的右孩子
        q.push(rightNode->left);  // 右结点的左孩子
    }

    return true;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << isSymmetric(root) << endl;
    cout << isSymmetric2(root) << endl;

    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}
