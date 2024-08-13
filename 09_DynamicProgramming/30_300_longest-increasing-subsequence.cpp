/*
    Topic link: https://leetcode.cn/problems/longest-increasing-subsequence/
*/
#include <algorithm>
#include <iostream>
#include <vector>

int lengthOfLIS(std::vector<int> &nums) {
    if (nums.size() <= 1)
        return nums.size();

    std::vector<int> dp(nums.size(), 1);

    int res = 0;

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
        if (dp[i] > res)
            res = dp[i];
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    int res = lengthOfLIS(nums);

    std::cout << res << std::endl;
    return 0;
}
