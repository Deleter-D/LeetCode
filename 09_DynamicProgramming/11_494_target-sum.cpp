/*
    Topic link: https://leetcode.cn/problems/target-sum/
*/
#include "utils/DPUtils.h"
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int findTargetSumWays(std::vector<int> &nums, int target) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>());

    if (abs(target) > sum)
        return 0;
    if ((target + sum) % 2 != 0)
        return 0;

    int pack = (target + sum) / 2;
    std::vector<int> dp(pack + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = pack; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[pack];
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 1, 1, 1, 1};
    int target = 3;

    int res = findTargetSumWays(nums, target);

    std::cout << res << std::endl;
    return 0;
}
