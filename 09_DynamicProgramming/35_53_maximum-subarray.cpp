/*
    Topic link: https://leetcode.cn/problems/maximum-subarray/
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int maxSubArray(std::vector<int> &nums) {
    if (nums.size() == 1)
        return nums[0];

    std::vector<int> dp(nums.size(), 0);

    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
        res = std::max(res, dp[i]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int res = maxSubArray(nums);

    std::cout << res << std::endl;
    return 0;
}
