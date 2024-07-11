/*
    Topic link: https://leetcode.cn/problems/maximum-binary-tree/
*/
#include "utils/TreeNode.h"
#include <cassert>
#include <climits>
#include <vector>
using namespace std;

int argmax(vector<int> &nums) {
    int max = INT_MIN;
    int index = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max) {
            max = nums[i];
            index = i;
        }
    }
    return index;
}

TreeNode *traversal(vector<int> &nums) {
    if (nums.size() == 0)
        return nullptr;

    int max_idx = argmax(nums);
    TreeNode *root = new TreeNode(nums[max_idx]);

    vector<int> left_nums(nums.begin(), nums.begin() + max_idx);
    vector<int> right_nums(nums.begin() + max_idx + 1, nums.end());
    root->left = traversal(left_nums);
    root->right = traversal(right_nums);

    return root;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return traversal(nums);
}

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(0);

    vector<int> nums{3, 2, 1, 6, 0, 5};

    TreeNode *res = constructMaximumBinaryTree(nums);

    assert(res->val == root->val);
    assert(res->left->val == root->left->val);
    assert(res->left->right->val == root->left->right->val);
    assert(res->left->right->right->val == root->left->right->right->val);
    assert(res->right->val == root->right->val);
    assert(res->right->left->val == root->right->left->val);
    return 0;
}
