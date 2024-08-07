/*
    Topic link: https://leetcode.cn/problems/combination-sum-iv/
*/
#include <iostream>
#include <vector>

int combinationSum4(std::vector<int> &nums, int target) {
    std::vector<int> dp(target + 1, 0);

    dp[0] = 1;

    for (int j = 1; j <= target; j++) {
        for (int i = 0; i < nums.size(); i++) {
            if (j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]])
                dp[j] += dp[j - nums[i]];
        }
    }

    return dp[target];
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 2, 3};
    int target = 4;

    int res = combinationSum4(nums, target);

    std::cout << res << std::endl;
    return 0;
}
