/*
    Topic link:
   https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
*/
#include <algorithm>
#include <iostream>
#include <vector>

int findLengthOfLCIS(std::vector<int> &nums) {
    if (nums.size() <= 1)
        return nums.size();

    std::vector<int> dp(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1])
            dp[i] = dp[i - 1] + 1;
    }

    int res = 0;
    std::for_each(dp.begin(), dp.end(), [&res](int i) {
        if (i > res)
            res = i;
    });

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 3, 5, 4, 7};

    int res = findLengthOfLCIS(nums);

    std::cout << res << std::endl;
    return 0;
}
