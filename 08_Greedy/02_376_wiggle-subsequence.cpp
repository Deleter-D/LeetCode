/*
    Topic link: https://leetcode.cn/problems/wiggle-subsequence/
*/
#include <iostream>
#include <vector>

int wiggleMaxLength(std::vector<int> &nums) {
    if (nums.size() <= 1)
        return nums.size();

    int res = 1;

    int curDiff = 0;
    int preDiff = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        curDiff = nums[i + 1] - nums[i];
        if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
            res++;
            preDiff = curDiff;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};

    int res = wiggleMaxLength(nums);

    std::cout << res << std::endl;
    return 0;
}
