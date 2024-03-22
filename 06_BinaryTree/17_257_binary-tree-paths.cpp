/*
    Topic link: https://leetcode.cn/problems/binary-tree-paths/
*/
#include "../utils/TreeNode.h"
#include <string>
#include <vector>
using namespace std;

void traversal(TreeNode *node, vector<int> &path, vector<string> &res) {
    path.push_back(node->val); // 当前结点的值存入path数组
    // 碰到叶子结点
    if (node->left == nullptr && node->right == nullptr) {
        string sPath;
        for (int i = 0; i < path.size() - 1; i++) {
            sPath += to_string(path[i]);
            sPath += "->";
        }
        sPath += to_string(path[path.size() - 1]);
        res.push_back(sPath);
        return;
    }
    // 处理左子树
    if (node->left != nullptr) {
        traversal(node->left, path, res);
        path.pop_back(); // 回溯
    }
    // 处理右子树
    if (node->right != nullptr) {
        traversal(node->right, path, res);
        path.pop_back(); // 回溯
    }
}

vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    vector<int> path;
    if (root == nullptr)
        return res;
    traversal(root, path, res);
    return res;
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}
