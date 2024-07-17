/*
    Topic link:
   https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
*/
#include "utils/TreeNode.h"
#include <climits>
#include <cstdlib>
#include <system_error>
#include <vector>
using namespace std;

TreeNode *traversal(vector<int> &nums, int begin, int end) {
    if (begin > end)
        return nullptr;

    int mid = (end - begin) / 2 + begin;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = traversal(nums, begin, mid - 1);
    root->right = traversal(nums, mid + 1, end);

    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
    return traversal(nums, 0, nums.size() - 1);
}

int main(int argc, char *argv[]) {

    vector<int> nums{-10, -3, 0, 5, 9};
    TreeNode *res = sortedArrayToBST(nums);
    return 0;
}
